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
void findmiddle(Node* head)
{
    if(head == NULL)
    {
        cout<<"The list is empty."<<endl;
        return;
    }
    Node* slow = head;
    Node* fast = head;
    //Move fats by step 2 steps and slow by step 1
    while(fast != NULL && fast->next != NULL)
    {
        slow= slow->next;
        fast = fast->next->next;
    }
    cout<<"The middle element is: "<<slow->data<<endl;
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
    findmiddle(head);
    return 0;
}
