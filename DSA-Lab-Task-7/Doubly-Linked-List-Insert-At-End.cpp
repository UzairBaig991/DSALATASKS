#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *prev;
    Node *next;
};
void insertAtEnd(Node **head, int newData)
{
    Node *newNode = new Node();
    newNode->data = newData;
    newNode->next = NULL;
    if (*head == NULL)
    {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}
void printForward(Node *head)
{
    cout << "Forward Print: ";
    while (head != NULL)
    {
        cout << head->data << " <-> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}
void ReverseDisplay(Node *head)
{
    if (head == NULL)
    {
        cout << "List is Empty" << endl;
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
        cout << temp->data << " -> ";
        temp = temp->prev;
    }
    cout << "NULL" << endl;
}
int main()
{
    Node *head = NULL;
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    printForward(head);
    ReverseDisplay(head);
    return 0;
}