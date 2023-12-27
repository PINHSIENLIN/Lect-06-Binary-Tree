// Make a phone book using a binary search tree
// And create a menu to allow users to enter i to add a new node
// You can enter your name, phone number, and insert nodes according to the alphabetical order of the name 
// (assuming that the entered name will not be repeated)
// enter
// l All node contents can be printed out in order of name (each piece of data is printed with two line breaks)
// m can print out the contents of all nodes in the order of their names.
// n can print out all node contents in order of name
// d Delete a name in the link list that is the same as the input and print delete [name] ok (wrap twice), if there is no such name, print cannot delete
// f Search for a name in the link sequence that is the same as the input (the data is printed and wrapped twice). If there is no such name, not found is output.
// q Exit the program

#include <iostream>
#include <string>
using namespace std;

// Preoder Traversal, Inorder Traversal, Postorder Traversal

// Create a structure of Node that contains data and pointer to left child and pointer to right child
struct Node {
    string name;
    string phone;
    Node *left, *right;
};

// Function to print Preorder Traversal
void printPreorder(Node *root){
   
     if (root == NULL) return;
    cout << "Name: " << root->name << endl;
    cout << "Phone: " << root->phone << endl;
    cout << endl;
    printPreorder(root->left);
    printPreorder(root->right);
}

// Function to print Inorder Traversal
void printInorder(Node *root){
   
     if (root == NULL) return ;
    printInorder(root->left);
    cout << "Name: " << root->name << endl;
    cout << "Phone: " << root->phone << endl;
    cout << endl;
    printInorder(root->right);
}

// Function to print Postorder Traversal
void printPostorder(Node *root){
   
     if (root == NULL) return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout << "Name: " << root->name << endl;
    cout << "Phone: " << root->phone << endl;
    cout << endl;
}

// Function to search for a node in BST recursively
Node* searchNode(Node* root, string data) {
  // Base case
    if (root == NULL) {
        return NULL;
  }

  // Compare data with the current node's data
  if (data == root->name) {
     return root; // Node found
  } else if (data < root->name) {
    return searchNode(root->left, data); // Search left subtree
  } else {
    return searchNode(root->right, data); // Search right subtree
  }
}

// Utility function to create a new tree node for root
Node* newNode(string name, string phone)
{
    Node* temp = new Node;
    temp->name = name;
    temp->phone = phone;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert a node in BST recursively
Node* insert_binary_tree(Node* root, string name, string phone){
      
      // Consider if it is a root 
      if (root == NULL){
        return newNode(name,phone);
      }
      
      // To left subtree
      if (root->name > name){
        root->left = insert_binary_tree(root->left, name, phone);
      }  // To right subtree
      else if (root->name < name){
        root->right = insert_binary_tree(root->right, name, phone);
      }
     
     return root;
}

// Delete a node for binary search tree

// Consider a tree has left subtree and right subtree, so need to find the minimum
// Function to find the minimum node in a subtree
Node* findMinimum(Node* root){
       while (root->left != NULL){
           root = root->left;
       }
       return root;      
}

// Function to delete a node in BST recursively
Node* deleteNode(Node* root, string target){
    // Base case
    if (root == NULL){
        return root;
    } 
    
    // Left Subtree
    if (target < root->name){
        root->left = deleteNode(root->left, target);
    } 
    // Right Subtree
    else if (target > root->name){
        root->right = deleteNode(root->right, target);
    } 
    else {
        // Case 1: No child
        if (root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        // Case 2: One child
        else if (root->left == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else if (root->right == NULL){
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        // Case 3: Two children
        else {
            Node* temp = findMinimum(root->right);
            root->name = temp->name;
            root->right = deleteNode(root->right, temp->name);
        }
    }
    return root;
}

int main(){
    
    char choice;
    
    Node* root = NULL;

    while (true)
    {
        cin >> choice;
        if (choice == 'i'){
            string name, phone;
            cin >> name;
            cin >> phone;
            root = insert_binary_tree(root,name,phone);
        }
        else if (choice == 'l'){
            printInorder(root);
        }
        else if (choice == 'm'){
            printPreorder(root);   
        }
        else if (choice == 'n'){
            printPostorder(root);   
        }
        else if (choice == 'd'){
            string data;
            cin >> data;
            root = deleteNode(root,data);
            if (root->name == data){
                cout << "delete " << data << " ok" << endl;
            } else {
                cout << "cannot delete" << endl;
            }
        }
        else if (choice == 'f'){
            string data;
            cin >> data;
            if (searchNode(root,data) != NULL){
                cout << "found:"<< endl;
                cout << "Name: " << root->right->name << endl;
                cout << "Phone: " << root->right->phone << endl << endl;
            } else{
                cout << "not found" << endl;
            }
        }
        else if (choice == 'q'){
            break;
        }
    }
    
    return 0;
}