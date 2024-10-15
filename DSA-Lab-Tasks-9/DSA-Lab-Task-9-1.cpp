#include <iostream>
#include <string>
using namespace std;
class student 
{
private:
    int reg_no;          //Registration number
    string st_name;      //Student name
    float cgpa;          //Student CGPA
public:
    student() 
    {
        reg_no = 0;
        st_name = " ";
        cgpa = 0.0;
    }
    void input() 
    {
        cout <<"Enter Registration Number: ";
        cin >> reg_no;
        cout <<"Enter Student Name: ";
        cin.ignore();  
        getline(cin, st_name); 
        cout << "Enter CGPA: ";
        cin >> cgpa;
    }
    void output() 
    {
        cout << "\t*****STUDENT DETAILS******\t\n";
        cout << "Registration Number: " << reg_no << endl;
        cout << "Name: " << st_name << endl;
        cout << "CGPA: " << cgpa << endl;
    }
};
class Stack 
{
private:
    student* arr;       //Dynamic array to store students
    int top;            //Keeps track of the top of the stack
    int capacity;       // Maximum size of the stack
public:
    Stack(int size) 
    {
        arr = new student[size];  
        top = -1;  
        capacity = size;  
    }
    ~Stack() 
    {
        delete[] arr; 
    }
    void push(student s) 
    {
        if (top == capacity - 1) 
        {
            cout << "Stack is full, can't push more students.\n";
        }
        else 
        {
            top++; 
            arr[top] = s; 
            cout << "Student added to the stack.\n";
        }
    }
    void pop() 
    {
        if (top == -1) 
        {
            cout << "Stack is empty, nothing to pop.\n";
        } 
        else 
        {
            cout << "Removing student from the stack...\n";
            arr[top].output();  
            top--;  
        }
    }
};

int main() 
{
    int stackSize;
    int choice = 0; 
    cout<< "\tNAME : UZAIR BAIG\t"<<endl;
    cout<< "\tSAP ID : 55225\t"<<endl;
    cout << "Enter the size of the stack: ";
    cin >> stackSize;
    Stack s(stackSize);
    while (choice != 3) 
    {
        cout<< "1. Add a student."<<endl;
        cout<< "2. Remove a student."<<endl;
        cout<< "3. Exit."<<endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1) 
        {
            student temp;  
            temp.input();  
            s.push(temp);  
        } 
        else if (choice == 2) 
        {
            s.pop(); 
        }
    }
    return 0;
}
