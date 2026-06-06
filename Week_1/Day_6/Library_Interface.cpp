#include <iostream>
#include <string>
using namespace std;

// Library Interface
class LibraryUser {
public:
    virtual void registerAccount() = 0;
    virtual void requestBook() = 0;

    virtual ~LibraryUser() {}
};

// KidUser class
class KidUser : public LibraryUser {
public:
    int age;
    string bookType;

    void registerAccount() override {
        if (age < 12) {
            cout << "You have successfully registered under a Kids Account"
                 << endl;
        } else {
            cout << "Sorry, Age must be less than 12 to register as a kid"
                 << endl;
        }
    }

    void requestBook() override {
        if (bookType == "Kids") {
            cout << "Book Issued successfully, please return the book within 10 days"
                 << endl;
        } else {
            cout << "Oops, you are allowed to take only kids books"
                 << endl;
        }
    }
};

// AdultUser class
class AdultUser : public LibraryUser {
public:
    int age;
    string bookType;

    void registerAccount() override {
        if (age > 12) {
            cout << "You have successfully registered under an Adult Account"
                 << endl;
        } else {
            cout << "Sorry, Age must be greater than 12 to register as an adult"
                 << endl;
        }
    }

    void requestBook() override {
        if (bookType == "Fiction") {
            cout << "Book Issued successfully, please return the book within 7 days"
                 << endl;
        } else {
            cout << "Oops, you are allowed to take only adult Fiction books"
                 << endl;
        }
    }
};

int main() {

    // Test Case #1 (KidUser)

    KidUser kid;

    cout << "Enter age for KidUser: ";
    cin >> kid.age; 

    kid.registerAccount();

    cout << "Enter book type for KidUser: ";
    cin >> kid.bookType;
    
    kid.requestBook();

    // Test Case #2 (AdultUser)
    AdultUser adult;

    cout << "Enter age for AdultUser: ";
    cin >> adult.age;

    adult.registerAccount();

    cout << "Enter book type for AdultUser: ";
    cin >> adult.bookType;

    adult.requestBook();

    return 0;
}