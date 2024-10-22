#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
};
//Function to create a new Node
Node* createNode(int value)
{
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}
//Function to insert a new Node
Node* insert(Node* root, int value)
{
    //if the tree is empty, return a new Node
    if(root == nullptr)
    {
        return createNode(value);
    }
    //Otherwise, recur down the trees
    if(value < root->data)
    {
        //Insert in the left subtree
        root->left = insert(root->left, value);
    }
    else if(value > root->data)
    {
        //Insert in the right subtree
        root->right = insert(root->right, value);
    }
    //Return the unchanged root pointer
    return root;
}
//Function to perform in-order traversel
void inOrderTraversel(Node* root)
{
    if(root == nullptr)
    {
        return;
    }
    inOrderTraversel(root->left);        //Visit left subtree   
    cout<<root->data<<" ";           //Print the Node's value            
    inOrderTraversel(root->right);       //visit right subtree
}
int main()
{
    Node* root = nullptr;      //start with an empty tree
    int nodes, n;
    cout << "Enter the number of nodes you want to Enter: ";
    cin >> nodes;
    // Insert nodes into the BST based on user input
    for(int i = 0; i < nodes; i++) 
    {
        cout << "Enter the value for Node " << i+1 << ": ";
        cin >> n;
        root = insert(root, n);  // Insert the value into the tree
    }
    //Insert nodes into the BST
    /*root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);*/

    //Display the BST in in-order traversel
    cout<<"In-order Traversel of the BST: ";
    inOrderTraversel(root);
    return 0;
}