#include <iostream>
using namespace std;

int main() 
{
    int books[100];
    for (int i = 0; i < 100; i++) 
    {
        books[i] = 0;
    }
    cout << "Books are added in the Cupboard with 0 copies." << endl;
    int book_number, copies;
    cout << "Enter the book number (0-99) to add copies: ";
    cin >> book_number;
    if (book_number >= 0 || book_number < 100) 
    {
        cout << "Enter the number of copies to add for book " << book_number << ": ";
        cin >> copies;
        books[book_number] = copies;  
        cout << "\nAdded " << copies << " copies at book " << book_number << ".";
    } 
    else 
    {
        cout << "\nYou entered an invalid book number!!!" << endl;
        return 0;
    }
    cout << "\nEnter the book number (0-99) you want to borrow: ";
    cin >> book_number;
    if (book_number >= 0 || book_number < 100)
     {
        if (books[book_number] > 0 || books[book_number] < 100) 
        {
            books[book_number]--;  
            cout << "You borrowed a book.  " << endl;
        } 
        else 
        {
            cout << "There are no more copies of this book available." << endl;
        }
    } 
    else 
    {
        cout << "You entered an invalid book number!!!" << endl;
        return 0;
    }
    cout << "Enter the book number (0-99) you want to return: ";
    cin >> book_number;

    if (book_number >= 0 || book_number < 100) 
    {
        books[book_number]++;  
        cout << "You returned a book.  " << endl;
    } 
    else 
    {
        cout << "You entered an invalid book number!!!" << endl;
    }
    return 0;
}