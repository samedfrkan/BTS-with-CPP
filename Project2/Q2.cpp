#include<iostream>
using namespace std;

struct node {
	int data;

	struct node* left;
	struct node* right;
	node(int data) {
		this->data = data;
		left = right = NULL;
	}
};

node* insert(int key) {
	node* newnode = new node(key);
	newnode->data = key;
	newnode->left = newnode->right = NULL;

	return newnode;

}
void in_order(struct node* node) { // left-root-right
	if (node == NULL)
		return;

	in_order(node->left);
	cout << node->data << " ";
	in_order(node->right);

}
void pre_order(struct node* node) { // root - left - right
	if (node == NULL)
		return;

	cout << node->data << " ";
	pre_order(node->left);
	pre_order(node->right);
}
void post_order(struct node* node) { // left - right - root
	if (node == NULL)
		return;

	post_order(node->left);
	post_order(node->right);
	cout << node->data << " ";
}






int main() {
	struct node* root = insert(4);
	root->left = insert(12);
	root->right = insert(6);
	root->right->left = insert(7);
	root->right->right = insert(45);
	root->left->right = insert(1);

	cout << "Inorder traversal ";
	in_order(root);

	cout << "\nPreorder traversal ";
	pre_order(root);

	cout << "\nPostorder traversal ";
	post_order(root);
	printf("\n\n");








	system("pause");
}
