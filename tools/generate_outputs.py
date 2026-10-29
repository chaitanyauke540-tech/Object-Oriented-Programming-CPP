"""Compile C++ practicals, capture real Linux PTY sessions, and render PNGs.

Run from any directory with Python 3, Pillow, DejaVu Sans Mono, and g++.
Images contain captured console text, including terminal-echoed sample input.
"""
from pathlib import Path
import errno
import io
import os
import pty
import re
import select
import subprocess
import tempfile
import time
from PIL import Image, ImageDraw, ImageFont

ROOT = Path(__file__).resolve().parents[1]
FONT = Path('/usr/share/fonts/truetype/dejavu/DejaVuSansMono.ttf')

CASES = {
    '1': [('Enter Book Title: ', 'C++ Primer'), ('Enter Author Name: ', 'Lippman'),
          ('Enter ISBN: ', '9780321714114'), ('Enter Price: ', '500')],
    '2': [('Enter your choice: ', '1'), ('Enter Roll Number: ', '101'),
          ('Enter Name: ', 'Chaitanya Uke'), ('Enter Course: ', 'Computer Science'),
          ('Enter Admission Year: ', '2026'), ('Enter your choice: ', '2'),
          ('Enter your choice: ', '3'), ('Enter Roll Number to search: ', '101'),
          ('Enter your choice: ', '4')],
    '4_input': [('Enter Book ID: ', '102'), ('Enter Title: ', 'C++ Primer'),
                ('Enter Author: ', 'Lippman'), ('Enter Price (Rs.): ', '500')],
    '5_input': [('Enter Roll Number: ', '101'), ('Enter Name: ', 'Chaitanya Uke'),
                ('Enter Course: ', 'Computer Science'), ('Press Enter to exit...', '')],
    '6_input': [('Enter Employee ID: ', '101'), ('Enter Employee Name: ', 'Chaitanya Uke')],
    '7_input': [('Enter Name: ', 'Chaitanya Uke'), ('Enter Age: ', '20'),
                ('Enter Contact Number: ', '0000000000'), ('Enter Roll Number: ', '101'),
                ('Enter Branch: ', 'Computer Science')],
    '8_input': [('Enter Name: ', 'Chaitanya Uke'), ('Enter Age: ', '40'),
                ('Enter Contact: ', '0000000000'), ('Enter Employee ID: ', '101'),
                ('Enter Department: ', 'HR'), ('Enter Team Size: ', '8')],
    '9_input': [('Enter Registration No: ', 'CAR001'), ('Enter Brand: ', 'Toyota'),
                ('Enter Seating Capacity: ', '5'), ('Enter Registration No: ', 'TRUCK001'),
                ('Enter Brand: ', 'Tata'), ('Enter Load Capacity (tons): ', '12.5')],
}

EXPECTED = {
    '1': ['Title: C++ Primer', 'Price: 500'],
    '2': ['All Student Records', 'Record found:', 'Exiting system. Goodbye!'],
    '3': ['Alice Smith', 'Bob Jones'],
    '4': ['First Book Details:', 'Second Book Details:'],
    '4_input': ['Custom Book Record', 'C++ Primer'],
    '5': ['Name: Anjali'], '5_input': ['Name: Chaitanya Uke'],
    '6': ['Employee record created for Anjali', 'Employee record removed for Anjali'],
    '6_input': ['Employee record removed for Chaitanya Uke'],
    '7': ['Branch: Computer Science'], '7_input': ['Student Profile', 'Chaitanya Uke'],
    '8': ['Team Size: 8'], '8_input': ['Manager Dossier', 'Chaitanya Uke'],
    '9': ['Load Capacity: 12.5 tons'], '9_input': ['12.5 metric tons'],
    '10': ['Higher Marks: 90', 'Higher Price: 699.75', 'Higher Sensor Reading: 30.8'],
    '11': ['Employee IDs after swap: 102 101', 'Room Numbers after swap: 205 201',
           'Task Priorities after swap: 2.5 1.5'],
    '12': ['Stored Value: 100', 'Stored Value: 95.75', 'Stored Value: Computer Science'],
}


def capture(executable, case):
    master, slave = pty.openpty()
    process = subprocess.Popen([str(executable)], stdin=slave, stdout=slave, stderr=slave)
    os.close(slave)
    result, pending, index = b'', b'', 0
    deadline = time.monotonic() + 15
    try:
        while time.monotonic() < deadline:
            if select.select([master], [], [], 0.1)[0]:
                try:
                    block = os.read(master, 65536)
                except OSError as exc:
                    if exc.errno == errno.EIO:
                        break
                    raise
                if not block:
                    break
                result += block
                pending += block
                if index < len(case):
                    prompt, answer = case[index]
                    marker = prompt.encode()
                    if marker in pending:
                        pending = pending.split(marker, 1)[1]
                        os.write(master, (answer + '\n').encode())
                        index += 1
        else:
            raise TimeoutError('Program did not finish within 15 seconds')
        assert process.wait(timeout=2) == 0, 'Program returned a failure status'
        assert index == len(case), 'Not all sample input was consumed'
        return result.decode('utf-8').replace('\r\n', '\n').replace('\r', '').strip()
    finally:
        if process.poll() is None:
            process.kill()
            process.wait()
        os.close(master)


def render(text, title, destination):
    font = ImageFont.truetype(str(FONT), 24)
    small = ImageFont.truetype(str(FONT), 18)
    lines = text.splitlines()
    pad, line_height = 36, 35
    width = max(1100, int(max(font.getlength(line) for line in lines)) + 2 * pad)
    height = 120 + len(lines) * line_height + 86
    image = Image.new('RGB', (width, height), '#10151f')
    draw = ImageDraw.Draw(image)
    draw.rectangle((0, 0, width, 87), fill='#1d2738')
    draw.text((pad, 19), title, font=font, fill='#f5f7ff')
    draw.text((pad, 54), 'C++17 | Captured console output | Chaitanya Uke', font=small, fill='#aebed6')
    for row, line in enumerate(lines):
        draw.text((pad, 111 + row * line_height), line, font=font, fill='#e6edf7')
    draw.line((pad, height - 55, width - pad, height - 55), fill='#344359', width=1)
    draw.text((pad, height - 42), 'Process completed successfully | Exit code: 0', font=small, fill='#8bd5ac')
    buffer = io.BytesIO()
    image.save(buffer, format='PNG', optimize=True)
    temporary = destination.with_suffix('.png.tmp')
    temporary.write_bytes(buffer.getvalue())
    temporary.replace(destination)


def main():
    output = ROOT / 'outputs'
    output.mkdir(exist_ok=True)
    sources = sorted(ROOT.glob('practical*.cpp'),
                     key=lambda p: (int(re.search(r'\d+', p.name).group()), '_input' in p.stem))
    generated = []
    with tempfile.TemporaryDirectory() as temporary:
        for source in sources:
            executable = Path(temporary) / source.stem.replace(' ', '_')
            build = subprocess.run(['g++', '-std=c++17', '-Wall', '-Wextra', '-pedantic',
                                    str(source), '-o', str(executable)], capture_output=True, text=True)
            if build.returncode or build.stderr:
                raise RuntimeError(f'{source.name}: {build.stderr}')
            key = source.stem.removeprefix('practical ')
            text = capture(executable, CASES.get(key, []))
            assert all(expected in text for expected in EXPECTED[key]), (source.name, text)
            destination = output / (source.stem + '.png')
            render(text, source.stem.title().replace('_Input', ' — Interactive'), destination)
            generated.append(destination.name)
            print(f'PASS {source.name} -> {destination.name}', flush=True)
    for old in output.glob('*.png'):
        if old.name not in generated:
            old.unlink()
    assert len(generated) == 18
    print('18 fresh PNGs: 12 practicals and 6 interactive variants.')


if __name__ == '__main__':
    main()
