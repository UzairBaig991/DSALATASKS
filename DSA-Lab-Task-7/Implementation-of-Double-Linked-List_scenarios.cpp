#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev;
};
void insertAtPosition(Node** head, int newData, int position) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = nullptr;
    
    if (position < 0) {
        cout << "Position cannot be negative." << endl;
        delete newNode; 
        return;
    }
    if (*head == nullptr || position == 0) {
        newNode->prev = nullptr;
        if (*head != nullptr) {
            newNode->next = *head;
            (*head)->prev = newNode;
        } else {
            newNode->next = nullptr; 
        }
        *head = newNode; 
        return;
    }

    Node* current = *head;
    for (int i = 0; i < position - 1 && current->next != nullptr; i++) {
        current = current->next; 
    }
    if (current->next == nullptr) {
        current->next = newNode; 
        newNode->prev = current;
    } else {
        newNode->next = current->next; 
        newNode->prev = current; 
        current->next->prev = newNode; 
        current->next = newNode; 
    }
}
void deleteFromBeginning(Node** head) {
    if (*head == nullptr) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
    if (*head != nullptr) {
        (*head)->prev = nullptr; 
    }
    delete temp; 
}
void deleteFromEnd(Node** head) {
    if (*head == nullptr) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }
    Node* temp = *head;
    if (temp->next == nullptr) { 
        deleteFromBeginning(head);
        return;
    }
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->prev->next = nullptr; 
    delete temp; 
}
void deleteAtPosition(Node** head, int position) {
    if (*head == nullptr || position < 1) {
        cout << "Invalid position or list is empty." << endl;
        return;
    }
    Node* temp = *head;
    if (position == 1) {
        deleteFromBeginning(head); 
        return;
    }
    for (int i = 1; temp != nullptr && i < position; i++) {
        temp = temp->next; 
    }
    if (temp == nullptr) {
        cout << "Position is greater than the length of the list." << endl;
        return;
    }
    if (temp->next != nullptr) {
        temp->next->prev = temp->prev; 
    }
    if (temp->prev != nullptr) {
        temp->prev->next = temp->next; 
    }
    delete temp; 
}
void printForward(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    cout << "Forward Print: ";
    while (head != nullptr) {
        cout << head->data;
        if (head->next != nullptr) {
            cout << " -> ";
        }
        head = head->next;
    }
    cout << " -> NULL" << endl;
}
void deleteAllNodes(Node** head) {
    while (*head != nullptr) {
        deleteFromBeginning(head); 
    }
}
int main() {
    Node* head = nullptr;
    cout<<"\t UZAIR BAIG \t"<<endl;
    cout<<"\t SAP ID: 55225 \t\n"<<endl;
    cout << "Scenario 1: Deleting from an empty list:" << endl;
    deleteFromBeginning(&head);
    cout << "\nScenario 2: Inserting at a position greater than the length of the list:" << endl;
    insertAtPosition(&head, 10, 0); 
    insertAtPosition(&head, 20, 1); 
    printForward(head);
    insertAtPosition(&head, 30, 3); 
    printForward(head); 
    cout << "\nScenario 3: Deleting all nodes one by one:" << endl;
    deleteAllNodes(&head);
    printForward(head); 
    cout << "\nTrying to delete after all nodes are deleted:" << endl;
    deleteFromBeginning(&head);

    return 0;
}
