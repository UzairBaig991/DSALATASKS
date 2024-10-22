#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new Node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Function to insert a new Node
Node* insert(Node* root, int value) {
    // If the tree is empty, return a new Node
    if(root == nullptr) {
        return createNode(value);
    }
    // Otherwise, recur down the tree
    if(value < root->data) {
        // Insert in the left subtree
        root->left = insert(root->left, value);
    } else if(value > root->data) {
        // Insert in the right subtree
        root->right = insert(root->right, value);
    }
    // Return the unchanged root pointer
    return root;
}

// Function to perform post-order traversal
void postOrderTraversal(Node* root) {
    if(root == nullptr) {
        return;
    }
    postOrderTraversal(root->left);    // Visit left subtree
    postOrderTraversal(root->right);   // Visit right subtree
    cout << root->data << " ";         // Print the Node's value
}
int main() {
    Node* root = nullptr;    // Start with an empty tree
    int nodes, n;
    cout << "Enter the number of nodes you want to enter: ";
    cin >> nodes;
    // Insert nodes into the BST based on user input
    for(int i = 0; i < nodes; i++) {
        cout << "Enter the value for Node " << i+1 << ": ";
        cin >> n;
        root = insert(root, n);  // Insert the value into the tree
    }
    // Display the BST using post-order traversal
    cout << "Post-order Traversal of the BST: ";
    postOrderTraversal(root);   
    return 0;
}
