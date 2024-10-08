#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
    Node* prev;
};
void insertAtEnd(Node **head, int newData)
{
    Node *newNode = new Node();
    newNode->data = newData;
    newNode->next = NULL;
    if (*head == NULL) // If the list is empty
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
// Delete node from the beginning of the list
void deleteFromBeginning(Node** head)
{
    if (*head == NULL) // Empty list
    {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }
    Node* temp = *head;
    if (temp->next == NULL) // Only one node
    {
        *head = NULL;
        delete temp;
        return;
    }
    *head = (*head)->next;
    (*head)->prev = NULL;
    delete temp;
}
void deleteAtPosition(Node** head, int position)
{
    if (*head == NULL || position < 1)
    {
        cout << "Invalid position or list is empty." << endl;
        return;
    }
    Node* temp = *head;
    if (position == 1) // If deleting the first node
    {
        deleteFromBeginning(head);
        return;
    }
    for (int i = 1; temp != NULL && i < position; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL) 
    {
        cout << "Position is greater than the length of the list." << endl;
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
void printForward(Node *head)
{
    if (head == NULL) 
    {
        cout << "List is empty" << endl;
        return;
    }
    cout << "Forward Print: ";
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
void ReverseDisplay(Node *head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    cout << "Reverse Print: ";
    while (temp != NULL)
    {
        cout << temp->data;
        if (temp->prev != NULL)
        {
            cout << " -> ";
        }
        temp = temp->prev;
    }
    cout << " NULL" << endl;
}
int main()
{
    Node *head = NULL;
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);
    cout << "Before deletion:" << endl;
    printForward(head);
    ReverseDisplay(head);
    int position;
    cout << "Enter position to delete: ";
    cin >> position;
    deleteAtPosition(&head, position);
    cout << "After deleting from position " << position << ":" << endl;
    printForward(head);
    ReverseDisplay(head);
    cout << "\nDeleting from the beginning:" << endl;
    deleteFromBeginning(&head);
    printForward(head);
    ReverseDisplay(head);
    cout << "\nDeleting from the end:" << endl;
    deleteFromEnd(&head);
    printForward(head);
    ReverseDisplay(head);

    return 0;
}
