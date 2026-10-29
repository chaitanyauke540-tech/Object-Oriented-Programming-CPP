# Object-Oriented Programming in C++

C++ practicals maintained by [Chaitanya Uke](https://github.com/chaitanyauke540-tech).

## Overview

12 practicals across 18 standalone programs, covering classes, objects, constructors, destructors, inheritance, and templates. Interactive variants are available for practicals 4–9. Practicals 1 and 2 also accept console input.

## Program index

| Practical | Topic | Program | Interactive version | Output |
| --- | --- | --- | --- | --- |
| 1 | Book inventory — classes and objects | [Source](practical%201.cpp) | Built in | [Screenshot](outputs/practical%201.png) |
| 2 | Student records — arrays of objects and searching | [Source](practical%202.cpp) | Built in | [Screenshot](outputs/practical%202.png) |
| 3 | Employee records — encapsulation | [Source](practical%203.cpp) | — | [Screenshot](outputs/practical%203.png) |
| 4 | Bookstore — default and parameterized constructors | [Source](practical%204.cpp) | [Source](practical%204_input.cpp) | [Screenshot](outputs/practical%204.png) |
| 5 | Student details — this pointer | [Source](practical%205.cpp) | [Source](practical%205_input.cpp) | [Screenshot](outputs/practical%205.png) |
| 6 | Employee lifecycle — constructors and destructors | [Source](practical%206.cpp) | [Source](practical%206_input.cpp) | [Screenshot](outputs/practical%206.png) |
| 7 | Person and Student — single inheritance | [Source](practical%207.cpp) | [Source](practical%207_input.cpp) | [Screenshot](outputs/practical%207.png) |
| 8 | Person, Employee, Manager — multilevel inheritance | [Source](practical%208.cpp) | [Source](practical%208_input.cpp) | [Screenshot](outputs/practical%208.png) |
| 9 | Vehicle, Car, Truck — hierarchical inheritance | [Source](practical%209.cpp) | [Source](practical%209_input.cpp) | [Screenshot](outputs/practical%209.png) |
| 10 | Maximum of two values — function template | [Source](practical%2010.cpp) | — | [Screenshot](outputs/practical%2010.png) |
| 11 | Swapping values by reference — function template | [Source](practical%2011.cpp) | — | [Screenshot](outputs/practical%2011.png) |
| 12 | Generic storage and display — class template | [Source](practical%2012.cpp) | — | [Screenshot](outputs/practical%2012.png) |

## Files

- Root: 18 C++ source files, each with its own main function.
- [outputs/](outputs/README.md): fresh output images for all 12 practicals and 6 interactive variants.
- [.gitignore](.gitignore): compiler output, build directories, and editor files.

## Requirements

A C++17-capable compiler such as GCC or Clang, a terminal, and Git to clone the repository. No external libraries are required.

## Compile and run

1. Clone with `git clone https://github.com/chaitanyauke540-tech/Object-Oriented-Programming-CPP.git`.
2. Open the folder with `cd Object-Oriented-Programming-CPP`.
3. Create a build directory with `mkdir build`.
4. Compile one program: `g++ -std=c++17 -Wall -Wextra -pedantic "practical 1.cpp" -o build/practical1`.
5. Run with `./build/practical1` on Linux or macOS. With GCC on Windows, compile to `build/practical1.exe` and run `.\build\practical1.exe` in PowerShell.

Quote filenames because they contain spaces. Compile each file separately; every program defines its own main function. Replace `g++` with `clang++` to use Clang.

## Usage

- Practical 1 asks for a book title, author, ISBN, and price.
- Practical 2 provides a menu to add, list, or search student records; select 4 to exit. Records remain in memory for that run, up to 100 students.
- Practicals 4–9 have separate input variants for entering your own values. Practical 5's input variant waits for Enter before exiting.
- Practical 10 compares integer, double, and float values using a function template.
- Practical 11 swaps employee IDs, room numbers, and task priorities by reference.
- Practical 12 stores and displays integer, decimal, and text values using a class template.

Use valid numeric input where prompted. These examples do not implement persistent storage or robust invalid-input handling.

## Checks

All 18 programs compile with GCC 13.3.0 using C++17 and `-Wall -Wextra -pedantic`. All 18 pass valid-input smoke tests. Program links resolve to existing files.

## Output screenshots

[View all practical outputs](outputs/README.md). Images are rendered from actual Linux console sessions, including sample input echoed by the terminal. They are console-output captures, not desktop screenshots. Every program exits successfully.

Regenerate on Linux with Python 3.9+, Pillow, DejaVu Sans Mono, and GCC: `python3 tools/generate_outputs.py`. The generator compiles and runs all 18 programs, checks expected output, and replaces their PNGs.

## Contributions

Open an issue or pull request with a clear description. Compile and run affected programs, preserve their standalone structure, and update the index when adding a practical.

## Maintainer

[Chaitanya Uke](https://github.com/chaitanyauke540-tech)
"# Object-Oriented-Programming-CPP" 
