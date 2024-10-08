#include <iostream>
using namespace std;
struct Node 
{
    int data;
    Node* next;
    Node* prev;
};
void insertAtBeginning(Node** head, int newData) 
{
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->prev = NULL;
    newNode->next = *head;
    if (*head != NULL) 
    {
        (*head)->prev = newNode;
    }
    *head = newNode;
}
void insertAtEnd(Node** head, int newData) 
{
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = NULL;
    if (*head == NULL) 
    {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }
    Node* last = *head;
    while (last->next != NULL) 
    {
        last = last->next;
    }
    last->next = newNode;
    newNode->prev = last;
}
void insertAtPosition(Node** head, int newData, int position) 
{
    if (position <= 1) 
    {
        insertAtBeginning(head, newData);
        return;
    }
    Node* newNode = new Node();
    newNode->data = newData;
    Node* temp = *head;
    for (int i = 1; temp != NULL && i < position - 1; i++) 
    {
        temp = temp->next;
    }
    if (temp == NULL) 
    {
        cout << "Position is greater than the length of the list." << endl;
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    if (newNode->next != NULL) 
    {
        newNode->next->prev = newNode;
    }
}
void deleteFromBeginning(Node** head) 
{
    if (*head == NULL) 
    {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }
    Node* temp = *head;
    if (temp->next == NULL) 
    {
        *head = NULL;
    } 
    else 
    {
        *head = (*head)->next;
        (*head)->prev = NULL;
    }
    delete temp;
}
void deleteFromEnd(Node** head) 
{
    if (*head == NULL) 
    {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }
    Node* temp = *head;
    if (temp->next == NULL) 
    {
        *head = NULL;
        delete temp;
        return;
    }
    while (temp->next != NULL) 
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    delete temp;
}
void deleteAtPosition(Node** head, int position) 
{
    if (*head == NULL || position < 1) 
    {
        cout << "Invalid position or list is empty." << endl;
        return;
    }
    if (position == 1) 
    {
        deleteFromBeginning(head);
        return;
    }
    Node* temp = *head;
    for (int i = 1; temp != NULL && i < position; i++) 
    {
        temp = temp->next;
    }
    if (temp == NULL) 
    {
        cout << "The Position you enter is Greater." << endl;
        return;
    }
    if (temp->next != NULL) 
    {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) 
    {
        temp->prev->next = temp->next;
    }

    delete temp;
}
void printForward(Node* head) 
{
    if (head == NULL) 
    {
        cout << "List is empty." << endl;
        return;
    }
    while (head != NULL) 
    {
        cout << head->data;
        if (head->next != NULL) 
        {
            cout << " -> ";
        }
        head = head->next;
    }
    cout << " NULL" << endl;
}
int main() 
{
    Node* head = NULL;
    int data, position;
    cout<<"\t UZAIR BAIG \t"<<endl;
    cout<<"\t SAP ID: 55225 \t"<<endl;
    cout << "Enter the value to insert at beginning: ";
    cin >> data;
    insertAtBeginning(&head, data);
    cout << "Enter the value to insert at end: ";
    cin >> data;
    insertAtEnd(&head, data);
    cout << "Enter the value to insert at specific position: ";
    cin >> data;
    cout << "Enter position to insert: ";
    cin >> position;
    insertAtPosition(&head, data, position);
    cout << "\nList after insertions:" << endl;
    printForward(head);
    cout << "\nDeleting node from the beginning." << endl;
    deleteFromBeginning(&head);
    printForward(head);
    cout << "Deleting node from the end." << endl;
    deleteFromEnd(&head);
    printForward(head);
    cout << "Enter position to delete: ";
    cin >> position;
    deleteAtPosition(&head, position);
    printForward(head);
    return 0;
}
