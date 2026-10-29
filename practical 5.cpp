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

// Run the demonstration with the sample values below.
int main() {
    Student s1(101, "Anjali", "Computer Science");
    s1.displayDetails();
    return 0;
}
