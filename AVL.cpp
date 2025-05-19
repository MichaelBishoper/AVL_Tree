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

void preorder(Node* root) {
    if (root != nullptr) {
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
    }
}

void postOrderTraversal(Node* root)
{
    
    if (root != nullptr) {
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);

    // finally visit the node
    cout << root->data << " ";
    }
}

// Hard functions study closely for exam later
// Function to search a given key in bst
Node* searchNode(Node* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == nullptr || root->data == key) {
        return root;
    }

    if (root->data < key) {
        return searchNode(root->right, key);
    }

    return searchNode(root->left, key);
}

// Function to find the inorder successor
Node* minValueNode(Node* node)
{
    Node* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

// Function to delete a node from gfg
Node* deleteNode(Node* root, int data)
{
    if (root == nullptr)
        return root;

    // If the data to be deleted is smaller than the root's
    // data, then it lies in the left subtree
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    }
    // If the data to be deleted is greater than the root's
    // data, then it lies in the right subtree
    else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    }
    // if data is same as root's data, then This is the node
    // to be deleted
    else {
        // node with only one child or no child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // node with two children: Get the inorder successor
        // (smallest in the right subtree)
        Node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}



int main() {
    int Usr_Input;
    int Usr_Data;
    Node* root = nullptr;

    // Menu

    while (true) {
    cout << "Choose an operation:\n [0] Exit\n [1] Create Tree\n [2] Insert Value\n [3] Print Tree (Inorder)\n [4] Print Tree (Preorder)\n [5] Print Tree (Postorder)\n [6] Delete Node" << endl;
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
                cout << "Root has a value already! Choose [6] if you want to delete!\n";
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
            cout << "The new tree is: ";
            inorderTraversal(root);
            cout << endl;
            break;
            } else {
                cout << "Create a tree first, choose [1] to do so!" << endl;
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
        case 4:
            if(root != nullptr){
                cout << "Current Tree: ";
                preorder(root);
                cout << endl;
                break;
            } else {
                cout << "Create a tree first, choose [1] to do so!" << endl;
                break;
            }
        case 5:
            if(root != nullptr){
                cout << "Current Tree: ";
                postOrderTraversal(root);
                cout << endl;
                break;
            } else {
                cout << "Create a tree first, choose [1] to do so!" << endl;
                break;
            }
        case 6:
            if(root != nullptr){
                cout << "Enter a value that you wish to be slain: " << endl;
                cin >> Usr_Data;
                if (Usr_Data != 188001) {
                    deleteNode(root, Usr_Data);
                    cout << "New tree: ";
                    inorderTraversal(root);
                    cout << endl;
                } else {
                    break;
                }
            } else {
                cout << "Create a tree first, choose [1] to do so!" << endl;
                break;
            }
        default:
            cout << "Invalid option" << endl;
            break;
    
    }
    }
    return 0;
}