#include <iostream>
#include <string>
using namespace std;

class Library
{
private:
    int bookID;
    string title;
    string author;
    int availableCopies;

public:
    static int totalBooks;

    void addBook()
    {
        cout << "Enter Book ID: ";
        cin >> bookID;

        cout << "Enter Book Title: ";
        cin >> title;

        cout << "Enter Author Name: ";
        cin >> author;

        cout << "Enter Available Copies: ";
        cin >> availableCopies;

        totalBooks += availableCopies;
    }

    void issueBook()
    {
        if (availableCopies > 0)
        {
            availableCopies--;
            totalBooks--;
            cout << "Book Issued Successfully\n";
        }
        else
        {
            cout << "Book Not Available\n";
        }
    }

    void returnBook()
    {
        availableCopies++;
        totalBooks++;
        cout << "Book Returned Successfully\n";
    }

    void displayBook()
    {
        cout << "\nBook ID: " << bookID;
        cout << "\nTitle: " << title;
        cout << "\nAuthor: " << author;
        cout << "\nAvailable Copies: " << availableCopies << endl;
    }

    static void showTotalBooks()
    {
        cout << "\nTotal Books in Library: " << totalBooks << endl;
    }
};

int Library::totalBooks = 0;

int main()
{
    Library b[5];
    int choice, count = 0;

    do
    {
        cout << "\n----- Library Menu -----";
        cout << "\n1. Add Book";
        cout << "\n2. Issue Book";
        cout << "\n3. Return Book";
        cout << "\n4. Display Book";
        cout << "\n5. Display Total Books";
        cout << "\n6. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (count < 5)
            {
                b[count].addBook();
                count++;
            }
            else
            {
                cout << "Library is full\n";
            }
            break;

        case 2:
        {
            int n;
            cout << "Enter book number to issue (0 to " << count - 1 << "): ";
            cin >> n;

            if (n >= 0 && n < count)
                b[n].issueBook();
            else
                cout << "Invalid book number\n";

            break;
        }

        case 3:
        {
            int n;
            cout << "Enter book number to return (0 to " << count - 1 << "): ";
            cin >> n;

            if (n >= 0 && n < count)
                b[n].returnBook();
            else
                cout << "Invalid book number\n";

            break;
        }

        case 4:
        {
            int n;
            cout << "Enter book number to display (0 to " << count - 1 << "): ";
            cin >> n;

            if (n >= 0 && n < count)
                b[n].displayBook();
            else
                cout << "Invalid book number\n";

            break;
        }

        case 5:
            Library::showTotalBooks();
            break;

        case 6:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 6);

    return 0;
}

