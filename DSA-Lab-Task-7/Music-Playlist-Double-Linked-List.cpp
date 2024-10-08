#include <iostream>
#include <string>
using namespace std;
struct Song 
{
    string title;
    Song* next;
    Song* prev;
};
void addSong(Song** head, string title) 
{
    Song* newSong = new Song();
    newSong->title = title;
    newSong->next = nullptr;
    if (*head == nullptr) 
    { 
        newSong->prev = nullptr;
        *head = newSong;
        return;
    }
    Song* last = *head;
    while (last->next != nullptr) 
    { 
        last = last->next;
    }
    last->next = newSong; 
    newSong->prev = last; 
}
void printForward(Song* head) 
{
    if (head == nullptr) 
    {
        cout << "The playlist is empty." << endl;
        return;
    }
    cout << "Playlist (Forward): ";
    while (head != nullptr) 
    {
        cout << head->title;
        if (head->next != nullptr) 
        {
            cout << " -> ";
        }
        head = head->next;
    }
    cout << endl;
}
void printBackward(Song* head) 
{
    if (head == nullptr) 
    {
        cout << "The playlist is empty." << endl;
        return;
    }
    Song* last = head;
    while (last->next != nullptr) 
    {
        last = last->next;
    }
    cout << "Playlist (Backward): ";
    while (last != nullptr) 
    {
        cout << last->title;
        if (last->prev != nullptr) 
        {
            cout << " -> ";
        }
        last = last->prev;
    }
    cout << endl;
}
void deleteSong(Song** head, string title) 
{
    if (*head == nullptr) 
    { 
        cout << "The playlist is empty. Nothing to delete." << endl;
        return;
    }
    Song* current = *head;
    while (current != nullptr && current->title != title) 
    {
        current = current->next;
    }
    if (current == nullptr) 
    {
        cout << "Song not found in the playlist." << endl;
        return;
    }
    if (current == *head) 
    {
        *head = current->next; 
        if (*head != nullptr) 
        {
            (*head)->prev = nullptr; 
        }
        delete current;
        cout << "Deleted: " << title << endl;
        return;
    }
    if (current->next != nullptr) 
    {
        current->next->prev = current->prev;
    }
    if (current->prev != nullptr) 
    {
        current->prev->next = current->next;
    }
    delete current; // Free memory
    cout << "Deleted: " << title << endl;
}
int main() 
{
    Song* head = nullptr;
    int choice;
    string title;
    cout<<"\t UZAIR BAIG \t"<<endl;
    cout<<"\t SAP ID: 55225 \t\n"<<endl;
    while (true) 
    {
        cout << "\n--- Music Playlist Menu ---\n";
        cout << "1. Add a song to the playlist\n";
        cout << "2. Print playlist (Forward)\n";
        cout << "3. Print playlist (Backward)\n";
        cout << "4. Delete a song from the playlist\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 
        if (choice == 1) 
        {
            cout << "Enter song title: ";
            getline(cin, title);
            addSong(&head, title);
        } 
        else if (choice == 2) 
        {
            printForward(head);
        } 
        else if (choice == 3) 
        {
            printBackward(head);
        } 
        else if (choice == 4) 
        {
            cout << "Enter song title to delete: ";
            getline(cin, title);
            deleteSong(&head, title);
        } else if (choice == 5) 
        {
            cout << "Program Exits" << endl;
            break; 
        } else 
        {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    while (head != nullptr) 
    {
        deleteSong(&head, head->title);
    }
    return 0;
}
