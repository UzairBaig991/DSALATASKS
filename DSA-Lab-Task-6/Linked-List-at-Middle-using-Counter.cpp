#include<iostream>
using namespace std;
struct Node 
{
    int data;
    Node* next;
};
void insertAtEnd(Node** head, int newData) 
{
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = NULL;
    if (*head == NULL) 
    {
        *head = newNode;
        return;
    }
    Node* last = *head;
    while (last->next != NULL) 
    {
        last = last->next;
    }
    last->next = newNode;
}
void findMiddle(Node* head) 
{
    if (head == NULL) 
    {
        cout << "The list is empty." << endl;
        return;
    }   
    int count = 0;
    Node* temp = head; 
    // Count the total number of nodes in the list
    while (temp != NULL) 
    {
        count++;
        temp = temp->next;
    }  
    // Find the middle position
    int middleIndex = count / 2;
    temp = head;   
    // Traverse to the middle node
    for (int i = 0; i < middleIndex; i++) 
    {
        temp = temp->next;
    }  
    cout << "The middle element is: " << temp->data << endl;
}
void printList(Node* node) 
{
    while (node != NULL) 
    {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "NULL" << endl;
}
int main() 
{
    Node* head = NULL;
    int n, value;    
    cout << "Please enter the number of elements you want to enter in the list: ";
    cin >> n;
    
    for (int i = 0; i < n; i++) 
    {
        cout << "Enter value at " << i + 1 << ": ";
        cin >> value;
        insertAtEnd(&head, value);
    }   
    cout << "Linked List elements: ";
    printList(head);   
    findMiddle(head);   
    return 0;
}
