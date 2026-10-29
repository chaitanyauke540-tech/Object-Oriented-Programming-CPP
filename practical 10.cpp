// Maintainer: Chaitanya Uke
// Practical 10: Function template: maximum
// One function template compares values of the same type; each call selects its type argument.

#include <iostream>

using namespace std;

template <typename T>
T myMax(T x, T y) {
    return (x > y) ? x : y;
}

// Run the demonstration with the sample values below.
int main() {
    cout << "=== Practical 10: Function Template (myMax) ===" << endl;

    cout << "Higher Marks: "
         << myMax<int>(75, 90) << endl;

    cout << "Higher Price: "
         << myMax<double>(499.50, 699.75) << endl;

    cout << "Higher Sensor Reading: "
         << myMax<float>(25.5f, 30.8f) << endl;

    return 0;
}
