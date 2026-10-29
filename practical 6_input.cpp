// Maintainer: Chaitanya Uke
// Practical 6: Object lifetime
// The constructor announces creation; the destructor runs automatically when the object leaves scope.

#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    int emp_id;
    string name;

public:

    Employee(int id, string n) {
        emp_id = id;
        name = n;
        cout << "\nEmployee record created for " << name << endl;
    }

    void display() {
        cout << "\n--- Employee Details ---" << endl;
        cout << "Employee ID: " << emp_id << endl;
        cout << "Employee Name: " << name << endl;
    }

    ~Employee() {
        cout << "Employee record removed for " << name << endl;
    }
};

// Read console input and display the resulting objects.
int main() {
    int id;
    string name;

    cout << "Enter Employee ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter Employee Name: ";
    getline(cin, name);

    Employee emp(id, name);

    emp.display();

    return 0;
}
