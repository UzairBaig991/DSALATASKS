#include<iostream>
using namespace std;
struct Node                //Define the structure for a node
{ 
    int data;             //Data to store
    Node* next;           //Pointer to the next node
};
// Function to insert a node at the end of the linked list
void insertAtEnd(Node** head, int newData) 
{
    Node* newNode = new Node();        //Allocate memory for new node
    newNode->data = newData;
    newNode->next = NULL; 
    if (*head == NULL) 
    {
        *head = newNode;           //If the list is empty, make the new node the head
        return;
    }
    Node* last = *head;           //Otherwise, traverse to the end of the list
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = newNode;         //Insert the new node at the end
}
//Function to insert a node at a specific position in the linked list
void insertAtPosition(Node** head, int newData, int position) 
{
    Node* newNode = new Node();      //Allocate memory for new node
    newNode->data = newData;
    newNode->next = NULL;     
    if (position == 1) 
    {
        newNode->next = *head;      //Insert at the beginning
        *head = newNode;
        return;
    }
    Node* temp = *head;
    for (int i = 1; temp != NULL && i < position - 1; i++) 
    {
        temp = temp->next;           //Traverse to the node before the position
    }
    if (temp == NULL) 
    {
        cout << "The Position you enter is in-correct." << endl;
        return;
    }

    newNode->next = temp->next;      //Insert at the desired position
    temp->next = newNode;
}
//Function to delete a node with a specific target value
void deleteNode(Node** head, int target) 
{
    Node* temp = *head;
    Node* prev = NULL;    
    if (temp != NULL && temp->data == target) 
    {
        *head = temp->next;       //If the node to be deleted is the head
        delete temp;              //Free the old head
        cout << "Node with value " << target << " deleted successfully." << endl;
        return;
    }
    while (temp != NULL && temp->data != target) 
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) 
    {
        cout << "Value " << target << " not found in the list." << endl;
        return;
    }
    prev->next = temp->next;        //Unlink the node from the list
    delete temp;                    //Free memory
    cout << "Node with value " << target << " deleted successfully." << endl;
}
//Function to search for a node with a specific target value
bool searchNode(Node* head, int target) 
{
    Node* current = head;
    while (current != NULL) 
    {
        if (current->data == target) 
        {
            return true;      //Target found
        }
        current = current->next;
    }
    return false;           //Target not found
}
//Function to print the linked list
void printList(Node* node) 
{
    if (node == NULL) 
    {
        cout << "The list is empty." << endl;
        return;
    }
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
    int value, position; 
    //Create a linked list with 'n' nodes
    cout << "Enter the number of nodes: ";
    int n;
    cin >> n; 
    for (int i = 0; i < n; i++) 
    {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;
        insertAtEnd(&head, value);       //Insert nodes at the end initially
    }  
    cout << "The linked list is: ";
    printList(head);
    cout << "Enter value and position to insert: ";
    cin >> value >> position;
    insertAtPosition(&head, value, position);
    cout << "The linked list after insertion is: ";
    printList(head);
    //Search for a value
    cout << "Enter value to search: ";
    cin >> value; 
    if (searchNode(head, value)) 
    {
        cout << "Value " << value << " found in the list." << endl;
    } 
    else 
    {
        cout << "Value " << value << " not found in the list." << endl;
    }
    // Delete a value
    cout << "Enter value to delete: ";
    cin >> value;
    deleteNode(&head, value);
    cout << "The linked list after deletion is: ";
    printList(head);
    return 0;
}
