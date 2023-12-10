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

// Function to find a Node with Preorder Traversal
bool search_Preorder(Node *temp, int target){
     // Check first root is NULL
     if (temp == NULL) return false;
     
     cout << temp->data << " ";
     // Check if current node is the target
     if(temp->data == target){
        return true;
     }
     
     // the function recursively calls itself on both the left and right subtrees
     return search_Preorder(temp->left, target) || search_Preorder(temp->right, target);
}

// Utility function to create a new tree node
Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int main(){
    // Level 1
    Node* root = newNode(5);
    // Level 2
    root->left = newNode(4);
    root->right = newNode(6);
    // Level 3
    root->left->left = newNode(2);
    root->right->right = newNode(8);
    // Level 4
    root->left->left->left = newNode(1);
    root->left->left->right = newNode(3);
    root->right->right->right = newNode(9);
    root->right->right->left = newNode(7);

    int num;
    cin >> num;
    if (search_Preorder(root,num)){
        cout << endl << "found " << num << endl;
    } else {
        cout << endl << "not found" << endl;
    }
    
    return 0;
}