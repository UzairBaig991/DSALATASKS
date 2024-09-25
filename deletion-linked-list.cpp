#include<iostream>
using namespace std;
struct Node        //Define the structure for the node
{
    int data;      //Data for store
    Node* next;    //Pointer to the next node
};
//Function to insert the node at the end
void insertatEnd(Node** head, int newData)
{
    Node* newNode = new Node();       //Allocate memory for new node
    newNode->data = newData;          //Assign data to the new node
    newNode->next = NULL;            //Make next or new node point to the current head
    if(*head == NULL)
    {
        *head = newNode;              //Move the head to pint to the new node
        return;
    }
    Node* last = *head;
    while(last->next != NULL)
    {
        last = last->next;
    }
    last->next = newNode;
}
//Function to print the llinked list
void deletelist(Node** head, int key)
{
    Node* temp = *head;
    Node* prev = NULL;   //if the heads node holds the key to be deleted
    if(temp != NULL && temp->data == key)
    {
        *head = temp->next;
        delete temp;
        return;
    }
    while(temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL)
    {
        cout<<" Value not found in the list." << endl;
        return;
    }
    prev->next = temp->next;
    delete temp;
}
void printlist(Node* node)
{
    while(node != NULL)
    {
        cout<<node->data<<" -> ";
        node = node->next;
    }
    cout<<"Null"<<endl;
}
int main()
{
    cout<<"\n**************LAb 05 Linked List******************\n"<<endl;
    int n;
    cout<<"Enter the value you want to enter in the linked list :";
    cin>>n;
    Node* head = NULL;
    for(int i = 0; i < n ; i++)
    {
        cout<<"Enter the value at " << i+1 <<" : ";
        int value;
        cin>>value;
        insertatEnd(&head,value);
        value == 0;
    }
    cout<<"Linked List: ";    //Print the linked list
    printlist(head);
    //Ask the user for the value to delete
    cout<<"Enter the vlaue to delete :";
    int deletevalue;
    cin>>deletevalue;
    deletelist(&head, deletevalue);  //delete the node with the specified value
    cout<<"Linked list after deletion is :";
    printlist(head);
    return 0;
}