#include <iostream>
using namespace std;
struct Node 
{
    int data;  
    Node* next;  
};
class Queue 
{
private:
    Node* front;  
    Node* rear;   
    int size;     
    int MAX_SIZE = 5;  
public:
    Queue() 
    {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }
    bool isFull() 
    {
        return size == MAX_SIZE;
    }
    bool isEmpty() 
    {
        return size == 0;
    }
    void enqueue(int value) 
    {
        if (isFull()) 
        {
            cout << "Queue alrady has many elements(Overflow).\n";
            return;
        }
        Node* newNode = new Node;  
        newNode->data = value;     
        newNode->next = nullptr;   
        if (isEmpty()) 
        {
            front = rear = newNode;
        } 
        else 
        {
            rear->next = newNode;
            rear = newNode;
        }
        size++;  
        cout << "Added " << value << " to the queue.\n";
    }
    int dequeue() 
    {
        if (isEmpty()) 
        {
            cout << "Queue dosn't have any element(Underflow).\n";
            return -1; 
        }

        Node* temp = front;  
        int value = temp->data;  
        front = front->next;  
        if (front == nullptr) 
        {
            rear = nullptr;
        }

        delete temp;  
        size--; 
        cout << "Removed " << value << " from the queue.\n";
        return value; 
    }
};
int main() 
{
    Queue queue1, queue2;  
    int choice, value;
    cout<<"\t NAME : UZAIR BAIG\t"<<endl;
    cout<<"\t SAP ID : 55225\t"<<endl;
    while (true) 
    {
        cout<<"1. Add to Queue 1."<<endl;
        cout<<"2. Remove from Queue 1 and Add to Queue 2."<<endl;
        cout<<"3. Remove from Queue 2."<<endl;
        cout<<"4. Exit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1) 
        {
            cout << "Enter a value to add to Queue 1: ";
            cin >> value;
            queue1.enqueue(value);  
        } 
        else if (choice == 2) 
        {
            value = queue1.dequeue(); 
            if (value != -1) 
            {  
                queue2.enqueue(value);  
            }
        } 
        else if (choice == 3) 
        {
            queue2.dequeue();  
        } 
        else if (choice == 4) 
        {
            break;
        } 
        else 
        {
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
