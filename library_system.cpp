#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>


using namespace std;

class Book {
public:
    Book(string title, string author, int year) : title_(title), author_(author), year_(year), available_(true) {}

    string getTitle() const { return title_; }
    string getAuthor() const { return author_; }
    int getYear() const { return year_; }
    bool isAvailable() const { return available_; }

    void setAvailable(bool available) { available_ = available; }

private:
    string title_;
    string author_;
    int year_;
    bool available_;
};

class Patron {
public:
    Patron(string name, string id) : name_(name), id_(id) {}

    string getName() const { return name_; }
    string getId() const { return id_; }

private:
    string name_;
    string id_;
};

class Library {
public:
    void addBook(const Book& book) {
        books_.push_back(book);
    }

    void displayBooks() const {
        if (books_.empty()) {
            cout << "There are no books in the library." << endl;
            return;
        }

        cout << "** Books in Library **" << endl;
        for (const Book& book : books_) {
            cout << "Title: " << book.getTitle() << endl;
            cout << "Author: " << book.getAuthor() << endl;
            cout << "Year: " << book.getYear() << endl;
            cout << "Available: " << (book.isAvailable() ? "Yes" : "No") << endl;
            cout << endl;
        }
    }

    void checkoutBook(const Patron& patron, string title) {
        for (Book& book : books_) {
            if (book.getTitle() == title && book.isAvailable()) {
                book.setAvailable(false);
                checkedOutBooks_[patron.getId()] = title;
                cout << "Book '" << title << "' checked out to patron " << patron.getName() << endl;
                return;
            }
        }
        cout << "Book '" << title << "' is not available or not found." << endl;
    }

    void returnBook(const Patron& patron, string title) {
        if (checkedOutBooks_.find(patron.getId()) != checkedOutBooks_.end() &&
            checkedOutBooks_[patron.getId()] == title) {
            for (Book& book : books_) {
                if (book.getTitle() == title) {
                    book.setAvailable(true);
                    checkedOutBooks_.erase(patron.getId());
                    cout << "Book '" << title << "' returned by patron " << patron.getName() << endl;
                    return;
                }
            }
        } else {
            cout << "Book '" << title << "' is not checked out by patron " << patron.getName() << endl;
        }
    }

private:
    vector<Book> books_;
    unordered_map<string, string> checkedOutBooks_; // Patron ID -> Book Title (for faster lookup)
};

int main() {
    Library library;

    // Add some sample books
    library.addBook(Book("The Lord of the Rings", "J.R.R. Tolkien", 1954));
    library.addBook(Book("Pride and Prejudice", "Jane Austen", 1813));
    library.addBook(Book("To Kill a Mockingbird", "Harper Lee", 1960));

    // Sample patrons
    Patron patron1("John Doe", "P123");
    Patron patron2("Jane Smith", "P456");

    // Library operations
    library.displayBooks();

    library.checkoutBook(patron1, "The Lord of the Rings");
    library.checkoutBook(patron2, "Pride and Prejudice");  // Not available
    library.checkoutBook(patron2, "To Kill a Mockingbird");

    library.displayBooks();

    library.returnBook(patron1, "The Lord of the Rings");
    library.returnBook(patron2, "To Kill a Mockingbird");  // Not checked out

    library.displayBooks();

    return 0;
}
