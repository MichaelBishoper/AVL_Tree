#include <bits/stdc++.h>
using namespace std; // eww

struct Node {
    int data;
    Node* left;
    Node* right;
    int height; // for AVL
};

// Create new node
Node* createNode(int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

Node* insertNode(Node* root, int data)
{
    if (root == nullptr) { 
                           
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

void inorderTraversal(Node* root)
{
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    int Usr_Input;
    int Usr_Data;
    Node* root = nullptr;

    // Menu

    while (true) {
    cout << "Choose an operation:\n [0] Exit\n [1] Create Node\n [2] Insert Node\n [3] Print Tree (Inorder)" << endl;
    cin >> Usr_Input;
  
    switch (Usr_Input) {
        case 1: 
            if(root == nullptr){
            cout << "Enter a value: " << endl;
            cin >> Usr_Data;
            root = createNode(Usr_Data);
            cout << "Current Tree: ";
            inorderTraversal(root);
            cout << endl;
            break;
            } else {
                cout << "Root has a value already! Use [4] to delete!\n";
                break;
            }
        case 0:
            cout << "Exiting menu...\n";
            return 0;
        case 2:
            if(root != nullptr){
            cout << "Enter a value to insert: " << endl;
            cin >> Usr_Data;
            insertNode(root, Usr_Data);
            cout << "The new tree is: " << endl;
            inorderTraversal(root);
            break;
            } else {
                cout << "Tree is still empty, please choose [1] to create a tree." << endl;
                break;
            }
        case 3:
            if(root != nullptr){
                cout << "Current Tree: ";
                inorderTraversal(root);
                cout << endl;
                break;
            } else {
                cout << "Create a tree first, choose [1] to do so!" << endl;
                break;
            }
    }
    }
    return 0;
}