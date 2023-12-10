// Binary search tree insertion algorithm
// And create a menu to allow users to enter i to add a new node
// You can enter numbers and insert nodes in numerical order (assuming the numbers entered will not be repeated)
// enter
// l can print out the contents of all nodes in inorder
// m can print out the contents of all nodes in preorder
// n can print out the contents of all nodes in postorder
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

// Function to find a Node with Preorder Traversal
bool search_Preorder(Node *temp, int target){
     // Check first root is NULL
     if (temp == NULL) return false;
     
     // Print out the searching process
     cout << temp->data << " ";
     // Check if current node is the target
     if(temp->data == target){
        return true;
     }
     
     // the function recursively calls itself on both the left and right subtrees
     return search_Preorder(temp->left, target) || search_Preorder(temp->right, target);
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

int main(){
    
    char choice;
    int data;
    Node* root = NULL;

    while (true)
    {
        cin >> choice;
        if (choice == 'i'){
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
        else if (choice == 'q'){
            break;
        }
    }
    
    return 0;
}