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
        cout << "Employee record created for " << name << endl;
    }

    void display() {
        cout << "Employee ID: " << emp_id << endl;
        cout << "Employee Name: " << name << endl;
    }

    ~Employee() {
        cout << "Employee record removed for " << name << endl;
    }
};

// Run the demonstration with the sample values below.
int main() {

    Employee emp(101, "Anjali");

    emp.display();

    return 0;
}
