// Maintainer: Chaitanya Uke
// Practical 7: Single inheritance
// Student initializes shared Person fields through the base-class constructor.

#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string name;
    int age;
    string contact;

public:
    Person(string n, int a, string c) {
        name = n;
        age = a;
        contact = c;
    }
};

class Student : public Person {
private:
    int rollNumber;
    string branch;

public:

    Student(string n, int a, string c, int r, string b) : Person(n, a, c) {
        rollNumber = r;
        branch = b;
    }

    void display() const {
        cout << "\n--- Student Profile ---" << endl;
        cout << "Name:        " << name << endl;
        cout << "Age:         " << age << endl;
        cout << "Contact:     " << contact << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Branch:      " << branch << endl;
    }
};

// Read console input and display the resulting objects.
int main() {
    string name, contact, branch;
    int age, rollNumber;

    cout << "=== Student Registration Portal (Single Inheritance) ===" << endl;
    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Age: ";
    cin >> age;
    cin.ignore();

    cout << "Enter Contact Number: ";
    getline(cin, contact);

    cout << "Enter Roll Number: ";
    cin >> rollNumber;
    cin.ignore();

    cout << "Enter Branch: ";
    getline(cin, branch);

    Student s1(name, age, contact, rollNumber, branch);
    s1.display();

    return 0;
}
