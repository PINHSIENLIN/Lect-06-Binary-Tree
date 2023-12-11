// Binary search tree insertion algorithm
// And create a menu to allow users to enter '1' to add a new node
// You can enter numbers and insert nodes in numerical order (assuming the numbers entered will not be repeated)

// l can print out the contents of all nodes in order
// m can print out the contents of all nodes in preorder
// n can print out the contents of all nodes in sequence
// d deletes a number in the link sequence that is the same as the input. If there is no such number, cannot delete is output.
// f searches for a number in the link sequence that is the same as the input. If there is no such number, not found is output.
// q Exit the program

#include <iostream>
using namespace std;

// Preoder Traversal, Inorder Traversal, Postorder Traversal

// Create a structure of Node that contains data and pointer to left child and pointer to right child
struct Node {
    int data;
    Node *left, *right;
};

// Function to print Preorder Traversal
void printPreorder(Node *temp){
   
     if (temp == NULL) return;
    cout << temp->data << " ";
    printPreorder(temp->left);
    printPreorder(temp->right);
}

// Function to print Inorder Traversal
void printInorder(Node *temp){
   
     if (temp == NULL) return ;
    printInorder(temp->left);
    cout << temp->data << " ";
    printInorder(temp->right);
}

// Function to print Postorder Traversal
void printPostorder(Node *temp){
   
     if (temp == NULL) return;
    printPostorder(temp->left);
    printPostorder(temp->right);
    cout << temp->data << " ";
}

// Function to search for a node in BST recursively
Node* searchNode(Node* root, int data) {
  // Base case
    if (root == NULL) {
        return NULL;
  }

  // Compare data with the current node's data
  if (data == root->data) {
     return root; // Node found
  } else if (data < root->data) {
    return searchNode(root->left, data); // Search left subtree
  } else {
    return searchNode(root->right, data); // Search right subtree
  }
}

// Utility function to create a new tree node for root
Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert a node in BST recursively
Node* insert_binary_tree(Node* temp, int data){
      
      // Consider if it is a root 
      if (temp == NULL){
        return newNode(data);
      }
      
      // To left subtree
      if (temp->data > data){
        temp->left = insert_binary_tree(temp->left, data);
      }  // To right subtree
      else if (temp->data < data){
        temp->right = insert_binary_tree(temp->right, data);
      }
     
     return temp;
}

// Delete a node for binary search tree

// Consider a tree has left subtree and right subtree, so need to find the minimum
// Function to find the minimum node in a subtree
Node* findMinimum(Node* root){
       Node* current = root;
       while (current && current->left){
           current = current->left;
       }
       return current;      
}

// Function to delete a node in BST recursively
Node* deleteNode(Node* root, int target){
    // Base case
    if (root == NULL){
        return root;
    }
    
    // Left Subtree
    if (target < root->data){
        root->left = deleteNode(root->left, target);
    } 
    // Right Subtree
    else if (target > root->data){
        root->right = deleteNode(root->right, target);
    } 
    else {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL){
            delete root;
            root = NULL;
        }
        // Case 2: One child
        else if (root->left == NULL){
            Node* temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL){
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        // Case 3: Two children
        else {
            Node* temp = findMinimum(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
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
            int data;
            cin >> data;
            root = insert_binary_tree(root,data);
        }
        else if (choice == 'l'){
            printInorder(root);
            cout << endl;
        }
        else if (choice == 'm'){
            printPreorder(root);
            cout << endl;
        }
        else if (choice == 'n'){
            printPostorder(root);
            cout << endl;
        }
        else if (choice == 'd'){
            int data;
            cin >> data;
            if (deleteNode(root,data) != NULL){
                cout << "delete " << data << " ok" << endl;
            } else {
                cout << "cannot delete" << endl;
            }
        }
        else if (choice == 'f'){
            int data;
            cin >> data;
            if (searchNode(root,data) != NULL){
                cout << "found: " << data << endl;
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