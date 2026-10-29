// Maintainer: Chaitanya Uke
// Practical 1: Book inventory
// Private fields hold one book; public methods read and display its details.

#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;
    double price;

public:

    void recordBook() {
        cout << "Enter Book Title: ";
        getline(cin, title);

        cout << "Enter Author Name: ";
        getline(cin, author);

        cout << "Enter ISBN: ";
        getline(cin, isbn);

        cout << "Enter Price: ";
        cin >> price;
        cin.ignore();
    }

    void displayBook() {
        cout << "\n--- Book Information ---" << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Price: " << price << endl;
    }
};

// Read console input and display the resulting objects.
int main() {
    Book book;
    cout << "=== Digital Book Inventory System ===" << endl;

    book.recordBook();
    book.displayBook();

    return 0;
}
