// Make a phone book v2.0 using binary search tree
// Function:
// Enter ‘i’ to add a new node. You can enter your name, phone number, and the number will be automatically added.
// Insert nodes in alphabetical order by name (assuming the entered names will not be repeated)
// Enter 'd' followed by a name to associate the name in a data node
// Delete the same ones (assuming the entered numbers will not be repeated)
// Enter ‘r’ followed by the number to associate the number in a data node
// Identical ones will be deleted (the numbers will not be repeated, and the numbers will not need to be renumbered after deletion)
// Enter 'f' followed by a name to add the name in a data node
// The same person prints out the information
// Enter ‘l’ to print out the contents of all nodes in alphabetical order by name, first/middle/last order
// Enter 'q' to read and exit the program

#include <iostream>
#include <string>
using namespace std;

class Node {
    public:
        string name;
        string phone;
        Node* left;
        Node* right;
    // Constructor to initialize data and next pointer (Member Initialization)
    Node(string name, string phone) : name(name), phone(phone), left(nullptr), right(nullptr){}
};

class BinarySearchTree{
    private:
    Node* root;
    
    // Function to insert a node in BST recursively
    Node* insert(Node* root, string name, string phone){
      
      // Consider if it is a root 
      if (root == NULL){
        return new Node(name,phone);
      }
      
      // To left subtree
      if (root->name > name){
        root->left = insert(root->left, name, phone);
      }  // To right subtree
      else if (root->name < name){
        root->right = insert(root->right, name, phone);
      }
     return root;
    }

    // Function to search for a node in BST recursively
    Node* searchNode(Node* root, string target) {
        // Base case
            if (root == NULL) {
                return root;
        }

        // Compare data with the current node's data
        if (target == root->name) {
            return root; // Node found
        } else if (target < root->name) {
            return searchNode(root->left, target); // Search left subtree
        } else {
            return searchNode(root->right, target); // Search right subtree
        }
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
Node* deleteNode(Node* root, string target, bool& found){
    // Base case
    if (root == NULL){
        found = false;
        return root;
    } 
    
    // Left Subtree
    if (target < root->name){
        root->left = deleteNode(root->left, target, found);
    } 
    // Right Subtree
    else if (target > root->name){
        root->right = deleteNode(root->right, target, found);
    } 
    else {
        // Case 1: No child
        if (root->left == NULL){
            Node* temp = root->right;
            delete root;
            found = true;
            return temp;
        }
        // Case 2: One child
        else if (root->right == NULL){
            Node* temp = root->left;
            delete root;
            found = true;
            return temp;
        }
        // Case 3: Two children
       
            Node* temp = findMinimum(root->right);
            root->name = temp->name;
            root->right = deleteNode(root->right, temp->name, found);
        
    }
    return root;
}

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

  public:
  BinarySearchTree() : root(nullptr) {}

   // Public method to insert a key into the BST
    void insert(string name, string phone) {
        root = insert(root, name, phone);
    }

    Node* searchNode(string target){
        return searchNode(root, target);
    };

    void deleteNode(string target){
        bool found = false;
        root = deleteNode(root, target, found);

        if (found){
            cout << "delete " << target << " ok" << endl << endl;
        } else {
            cout << "cannot delete" << endl;
        }
    }

    void printPreorder(){
       printPreorder(root);
    }

    void printInorder(){
       printInorder(root);
    }

    void printPostorder(){
       printPostorder(root);
    }
};

int main(){

    BinarySearchTree bst;

    char choice;
   
    while (true)
    {
        cin >> choice;
        if (choice == 'i'){
            string name, phone;
            cin >> name;
            cin >> phone;
            bst.insert(name, phone);
        }
        else if (choice == 'l'){
            cout << "Preorder Traversal: " << endl;
            bst.printPreorder();
            cout << "Inorder Traversal: " << endl;
            bst.printInorder();
            cout << "Postorder Traversal: " << endl;
            bst.printPostorder();
        }
        else if (choice == 'd'){
            string data;
            cin >> data;
            bst.deleteNode(data);
        }
        else if (choice == 'f'){
            string data;
            cin >> data;
            Node* result = bst.searchNode(data);
            if (result != NULL){
                cout << "found:"<< endl;
                cout << "Name: " << result->name << endl;
                cout << "Phone: " << result->phone << endl << endl;
            } else {
                cout << "not found" << endl;
            }
        }
        else if (choice == 'q'){
            break;
        }
    }

    // bst.insert("Peter","789");
    // bst.insert("Amy","123456789");
    // bst.insert("Zac","1234559");

    // bst.printInorder();
    // bst.printPostorder();
    // bst.printPreorder();

    return 0;
}