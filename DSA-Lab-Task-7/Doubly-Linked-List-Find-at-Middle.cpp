#include <iostream>
using namespace std;
struct Node 
{
    int data;
    Node* next;
    Node* prev;
};
void insertAtEnd(Node** head, int newData) 
{
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = nullptr;
    if (*head == nullptr) 
    { 
        newNode->prev = nullptr;
        *head = newNode;
        return;
    }
    Node* last = *head;
    while (last->next != nullptr) 
    { 
        last = last->next;
    }
    last->next = newNode; 
    newNode->prev = last; 
}
int findMiddle(Node* head) 
{
    if (head == nullptr) 
    {
        cout << "List is empty." << endl;
        return -1;
    }
    Node* slowPtr = head;
    Node* fastPtr = head;
    while (fastPtr != nullptr && fastPtr->next != nullptr) 
    {
        slowPtr = slowPtr->next; 
        fastPtr = fastPtr->next->next; 
    }
    return slowPtr->data; 
}
void printForward(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    cout << "Forward Print: ";
    while (head != nullptr) 
    {
        cout << head->data;
        if (head->next != nullptr) 
        {
            cout << " -> ";
        }
        head = head->next;
    }
    cout << " -> NULL" << endl;
}
int main() 
{
    Node* head = nullptr;
    int n;
    cout<<"\t UZAIR BAIG \t"<<endl;
    cout<<"\t SAP ID: 55225 \t"<<endl;
    cout << "Enter the size of the Nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int data;
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> data;
        insertAtEnd(&head, data);
    }
    printForward(head);
    int middleElement = findMiddle(head);
    if (middleElement != -1) {
        cout << "The middle element is: " << middleElement << endl;
    }
    return 0;
}
