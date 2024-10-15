#include <iostream>
using namespace std;

class Queue
{
    int a[5]; // Assuming a fixed size queue for now
    int rear;
    int front;
    int size = 5; // Setting the size of the queue

public:
    Queue()
    {
        rear = front = -1; // Initializing front and rear to -1
    }

    void enqueue(int x); // To add data to queue
    int dequeue();       // To remove data from queue
    void display();      // To display the queue contents
};

// Function to add data to the queue
void Queue::enqueue(int x)
{
    if (rear == size - 1)
    {
        cout << "Queue is full!" << endl;
    }
    else
    {
        if (front == -1)
        {
            front = 0; // If the queue is empty, update front
        }
        rear++;
        a[rear] = x;
        cout << x << " enqueued to the queue." << endl;
    }
}

// Function to remove data from the queue
int Queue::dequeue()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    else
    {
        int item = a[front];
        front++;
        if (front > rear)
        { // Queue becomes empty after dequeuing
            front = rear = -1;
        }
        return item;
    }
}

// Function to display the queue contents
void Queue::display()
{
    if (front == -1)
    {
        cout << "Queue is empty!" << endl;
    }
    else
    {
        cout << "Queue elements are: ";
        for (int i = front; i <= rear; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60); // Queue is full

    q.display();

    cout << q.dequeue() << " dequeued from the queue." << endl;
    cout << q.dequeue() << " dequeued from the queue." << endl;
    cout << q.dequeue() << " dequeued from the queue." << endl;
    q.enqueue(70);

    q.display();

    return 0;
}
