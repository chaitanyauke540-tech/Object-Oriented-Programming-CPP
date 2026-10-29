// Maintainer: Chaitanya Uke
// Practical 11: Function template: swap
// Reference parameters update the caller's variables using a temporary value.

#include <iostream>

using namespace std;

template <typename T>
void mySwap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

// Run the demonstration with the sample values below.
int main() {
    cout << "=== Practical 11: Function Template (mySwap) ===" << endl;

    int emp1 = 101, emp2 = 102;
    mySwap(emp1, emp2);
    cout << "Employee IDs after swap: "
         << emp1 << " " << emp2 << endl;

    int room1 = 201, room2 = 205;
    mySwap(room1, room2);
    cout << "Room Numbers after swap: "
         << room1 << " " << room2 << endl;

    float p1 = 1.5, p2 = 2.5;
    mySwap(p1, p2);
    cout << "Task Priorities after swap: "
         << p1 << " " << p2 << endl;

    return 0;
}
