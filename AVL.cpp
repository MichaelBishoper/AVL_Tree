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

    while (true) {
    cout << "Choose an operation:\n [0] Exit\n [1] Create Node\n [2] Insert Node" << endl;
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
    }
    }
    return 0;
}