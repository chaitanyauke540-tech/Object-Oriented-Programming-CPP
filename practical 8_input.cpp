// Maintainer: Chaitanya Uke
// Practical 8: Multilevel inheritance
// Manager extends Employee, which extends Person; each level initializes its own fields.

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

    void displayPerson() const {
        cout << "Name:        " << name << endl;
        cout << "Age:         " << age << endl;
        cout << "Contact:     " << contact << endl;
    }
};

class Employee : public Person {
protected:
    int employeeID;
    string department;

public:
    Employee(string n, int a, string c, int id, string dept) : Person(n, a, c) {
        employeeID = id;
        department = dept;
    }

    void displayEmployee() const {
        displayPerson();
        cout << "Employee ID: " << employeeID << endl;
        cout << "Department:  " << department << endl;
    }
};

class Manager : public Employee {
private:
    int teamSize;

public:
    Manager(string n, int a, string c, int id, string dept, int size)
        : Employee(n, a, c, id, dept) {
        teamSize = size;
    }

    void displayManager() const {
        cout << "\n--- Manager Dossier ---" << endl;
        displayEmployee();
        cout << "Team Size:   " << teamSize << endl;
    }
};

// Read console input and display the resulting objects.
int main() {
    string name, contact, department;
    int age, employeeID, teamSize;

    cout << "=== Workforce Management System (Multilevel Inheritance) ===" << endl;
    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Age: ";
    cin >> age;
    cin.ignore();

    cout << "Enter Contact: ";
    getline(cin, contact);

    cout << "Enter Employee ID: ";
    cin >> employeeID;
    cin.ignore();

    cout << "Enter Department: ";
    getline(cin, department);

    cout << "Enter Team Size: ";
    cin >> teamSize;

    Manager manager(name, age, contact, employeeID, department, teamSize);
    manager.displayManager();

    return 0;
}
