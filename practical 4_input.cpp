// Maintainer: Chaitanya Uke
// Practical 4: Book constructors
// The default constructor supplies a sample book; the parameterized constructor accepts custom values.

#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    int bookID;
    string title;
    string author;
    double price;

public:

    Book() {
        bookID = 101;
        title = "C++ Programming";
        author = "Bjarne Stroustrup";
        price = 500.00;
    }

    Book(int id, string t, string a, double p) {
        bookID = id;
        title = t;
        author = a;
        price = p;
    }

    void display() const {
        cout << "Book ID: " << bookID << endl;
        cout << "Title:   " << title << endl;
        cout << "Author:  " << author << endl;
        cout << "Price:   Rs. " << price << endl;
        cout << "------------------------------------" << endl;
    }
};

// Read console input and display the resulting objects.
int main() {
    int id;
    string title;
    string author;
    double price;

    cout << "=== Bookstore Inventory (Constructor Overloading) ===" << endl;

    Book book1;
    cout << "\n[Default Constructor Book Initialized]" << endl;
    book1.display();

    cout << "\n[Input Custom Book Details for Parameterized Constructor]" << endl;
    cout << "Enter Book ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter Title: ";
    getline(cin, title);

    cout << "Enter Author: ";
    getline(cin, author);

    cout << "Enter Price (Rs.): ";
    cin >> price;

    Book book2(id, title, author, price);

    cout << "\n--- Custom Book Record (Parameterized) ---" << endl;
    book2.display();

    return 0;
}
