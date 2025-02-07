#include<iostream>
using namespace std;

// Node structure for Binary Tree
struct node {
    int data;           
    struct node* left;  
    struct node* right; 

    // Constructor for node
    node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

// Function to create a new node and return its pointer
node* insert(int key) {
    // Create a new node and initialize its values
    node* newnode = new node(key);
    newnode->data = key;
    newnode->left = newnode->right = NULL;

    return newnode;
}

// Inorder traversal implementation (Left-Root-Right)
void in_order(struct node* node) {
    // Base case: if node is null, return
    if (node == NULL)
        return;

    // Recursively traverse left subtree
    in_order(node->left);
    // Print current node's data
    cout << node->data << " ";
    // Recursively traverse right subtree
    in_order(node->right);
}

// Preorder traversal implementation (Root-Left-Right)
void pre_order(struct node* node) {
    // Base case: if node is null, return
    if (node == NULL)
        return;

    // Print current node's data
    cout << node->data << " ";
    // Recursively traverse left subtree
    pre_order(node->left);
    // Recursively traverse right subtree
    pre_order(node->right);
}

// Postorder traversal implementation (Left-Right-Root)
void post_order(struct node* node) {
    // Base case: if node is null, return
    if (node == NULL)
        return;

    // Recursively traverse left subtree
    post_order(node->left);
    // Recursively traverse right subtree
    post_order(node->right);
    // Print current node's data
    cout << node->data << " ";
}

int main() {
    // Create the root node and build the binary tree
    struct node* root = insert(4);
    root->left = insert(6);
    root->right = insert(12);
    root->left->left = insert(45);
    root->left->right = insert(7);
    root->right->left = insert(1);

    // Print INORDER traversal
    cout << "Inorder traversal ";
    in_order(root);

    // Print PREORDeR traversal
    cout << "\nPreorder traversal ";
    pre_order(root);

    // Print POSTORDER traversal
    cout << "\nPostorder traversal ";
    post_order(root);
    printf("\n\n");

    system("pause");
    return 0;
}