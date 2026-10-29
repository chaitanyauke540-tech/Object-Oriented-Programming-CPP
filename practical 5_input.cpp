// Maintainer: Chaitanya Uke
// Practical 5: The this pointer
// Use this->member to distinguish object fields from constructor parameters with the same names.

#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    int rollNumber;
    string name;
    string course;

public:

    Student(int rollNumber, string name, string course) {
        this->rollNumber = rollNumber;
        this->name = name;
        this->course = course;
    }

    void displayDetails() {
        cout << "Student Details" << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Course: " << course << endl;
    }
};

// Read console input and display the resulting objects.
int main() {
    int rollNumber;
    string name;
    string course;

    cout << "Enter Roll Number: ";
    cin >> rollNumber;
    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Course: ";
    getline(cin, course);

    cout << endl;

    Student s1(rollNumber, name, course);
    s1.displayDetails();

    cout << "\nPress Enter to exit...";
    cin.get();

    return 0;
}
