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

    void display() {
        cout << "Book ID: " << bookID << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: Rs. " << price << endl;
        cout << "------------------------" << endl;
    }
};

// Run the demonstration with the sample values below.
int main() {

    Book book1;

    Book book2(102, "Object Oriented Programming", "Robert Lafore", 650.00);

    cout << "First Book Details:" << endl;
    book1.display();

    cout << "Second Book Details:" << endl;
    book2.display();

    return 0;
}
