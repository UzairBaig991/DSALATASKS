#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Function to insert a value into the BST
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

// Function to perform in-order traversal of the BST
void inOrderTraversal(Node* root) {
    if (root == nullptr)
        return;
    inOrderTraversal(root->left);
    cout << root->data << " "; // Visit the node
    inOrderTraversal(root->right);
}

// Function to sort the array using BST
void bstSort(int arr[], int size) {
    Node* root = nullptr;

    // Insert all elements of the array into the BST
    for (int i = 0; i < size; i++) {
        root = insert(root, arr[i]);
    }

    // Perform in-order traversal to get the sorted array
    cout << "Sorted array: ";
    inOrderTraversal(root);
    cout << endl;
}

int main() {
    int arr[] = {50, 30, 20, 40, 70, 60, 80}; // Example unsorted array
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Sort the array using BST
    bstSort(arr, size);

    return 0;
}
