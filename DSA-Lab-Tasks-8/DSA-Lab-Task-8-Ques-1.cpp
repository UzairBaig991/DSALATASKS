#include <iostream>
#include <string>
using namespace std;
class person 
{
private:
    int per_id;          //Person's ID
    string per_name;     //Person's Name
    int per_age;         //Person's Age
public:
    person() 
    {
        per_id = 0;
        per_name = " ";
        per_age = 0;
    }
    void input() 
    {
        cout << "Enter Person ID: ";
        cin >> per_id;
        cout << "Enter Person Name: ";
        cin.ignore();  
        getline(cin, per_name);  
        cout << "Enter Person Age: ";
        cin >> per_age;
    }
    void output() 
    {
        cout << "Person ID: " << per_id << endl;
        cout << "Person Name: " << per_name << endl;
        cout << "Person Age: " << per_age << endl;
    }
};
struct Node 
{
    person data;  
    Node* next;   
};
class Queue 
{
private:
    Node* front;  
    Node* rear;   
public:
    Queue() 
    {
        front = nullptr;  
        rear = nullptr;
    }
    bool isEmpty() 
    {
        return front == nullptr;
    }
    void addQueue(person p) 
    {
        Node* newNode = new Node;  
        newNode->data = p;         
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
        cout << "Person added to the queue.\n";
    }
    void removeQueue() 
    {
        if (isEmpty()) 
        {
            cout << "Queue is empty, cannot remove person.\n";
        } 
        else 
        {
            Node* temp = front;   
            front = front->next; 
            cout << "Removing person from the queue:\n";
            temp->data.output();  
            delete temp;
            if (front == nullptr) 
            {
                rear = nullptr;
            }
        }
    }
};
int main() 
{
    Queue q;  
    int choice;
    person p;
    cout<<"\t NAME : UZAIR BAIG\t"<<endl;
    cout<<"\t SAP ID : 55225\t"<<endl;
    while (true) 
    {
        cout<<"1. Add person to queue."<<endl;
        cout<<"2. Remove person from queue."<<endl;
        cout<<"3. Check if queue is empty."<<endl;
        cout<<"4. Exit."<<endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1) 
        {
            p.input();        
            q.addQueue(p);    
        } 
        else if (choice == 2) 
        {
            q.removeQueue();  
        } 
        else if (choice == 3) 
        {
            if (q.isEmpty()) 
            {
                cout << "Queue is empty.\n";
            } 
            else 
            {
                cout << "Queue is not empty.\n";
            }
        } 
        else if (choice == 4) 
        {
            break;  
        } 
        else 
        {
            cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}
