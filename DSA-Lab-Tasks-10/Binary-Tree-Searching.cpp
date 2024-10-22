#include<iostream>
using namespace std;
struct Node 
{
    int data;
    Node* left;
    Node* right;
};
// Function to create a new Node
Node* createNode(int value) 
{
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}
// Function to insert a new Node
Node* insert(Node* root, int value) 
{
    // If the tree is empty, return a new Node
    if(root == nullptr) 
    {
        return createNode(value);
    }
    // Otherwise, recur down the tree
    if(value < root->data) 
    {
        // Insert in the left subtree
        root->left = insert(root->left, value);
    } 
    else if(value > root->data) 
    {
        // Insert in the right subtree
        root->right = insert(root->right, value);
    }
    // Return the unchanged root pointer
    return root;
}
// Function to search for a value in the BST
bool search(Node* root, int value) 
{
    if(root == nullptr) 
    {
        return false;  // Return false if the tree is empty or the value is not found
    }
    if(root->data == value) 
    {
        return true;   // Value found
    }
    // Recur down the tree
    if(value < root->data) 
    {
        return search(root->left, value);  // Search in the left subtree
    } 
    else 
    {
        return search(root->right, value); // Search in the right subtree
    }
}
int main() 
{
    Node* root = nullptr;    // Start with an empty tree
    int nodes, n, searchValue;
    cout << "Enter the number of nodes you want to enter: ";
    cin >> nodes;
    // Insert nodes into the BST based on user input
    for(int i = 0; i < nodes; i++) 
    {
        cout << "Enter the value for Node " << i+1 << ": ";
        cin >> n;
        root = insert(root, n);  // Insert the value into the tree
    }
    // Input the value to search
    cout << "Enter the value to search in the BST: ";
    cin >> searchValue;
    // Search the tree
    if(search(root, searchValue)) 
    {
        cout << "Value " << searchValue << " found in the BST." << endl;
    } 
    else 
    {
        cout << "Value " << searchValue << " not found in the BST on any position." << endl;
    }   
    return 0;
}
