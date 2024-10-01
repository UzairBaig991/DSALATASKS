#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
void insertatEnd(Node** head, int newData)
{
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = NULL;
    if(*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node* last = *head;
    while(last->next != NULL)
    {
        last = last->next;
    }
    last->next = newNode;
}
void reverselist(Node** head)
{
    Node* prev = NULL;
    Node* current = *head;
    Node* next = NULL;
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}
void printlist(Node* node)
{
    while(node != NULL)
    {
        cout<< node->data << " -> ";
        node = node->next;
    }
    cout<<"NULL"<<endl;
}
int main()
{
    Node* head = NULL;
    int n, value;
    cout<<"Please enter the number of elements you want to enter in the list: ";
    cin>>n;
    for(int i = 0; i < n ; i++)
    {
        cout<<"Enetr value at "<< i+1 << ":";
        cin>>value;
        insertatEnd(&head, value);
    }
    cout<<"Linked List elements: ";
    printlist(head);
    cout<<"Linked List Before Reversing: ";
    printlist(head);
    cout<<"Linked List after Reversing: ";
    reverselist(&head);
    printlist(head);
    return 0;
}
