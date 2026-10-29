// Maintainer: Chaitanya Uke
// Practical 12: Class template: storage
// Each Data<T> object stores a value of its chosen type and displays it through the same interface.

#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Data {
private:
    T value;

public:

    Data(T v) {
        value = v;
    }

    void display() const {
        cout << "Stored Value: " << value << endl;
    }
};

// Run the demonstration with the sample values below.
int main() {
    cout << "=== Practical 12: Class Template (Data) ===" << endl;

    Data<int> d1(100);

    Data<double> d2(95.75);

    Data<string> d3("Computer Science");

    d1.display();
    d2.display();
    d3.display();

    return 0;
}
