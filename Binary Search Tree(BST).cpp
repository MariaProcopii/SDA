#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
};
//inorder traversal
void inorder(struct node *root) {
	if (root != NULL) {
		inorder(root->left);
		printf("%d  ", root->data);
		inorder(root->right);
	}
}
//Create a node
struct node* new_node(int data) {
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}
//insert node
struct node* insert(struct node* root, int data) {
	if (root == NULL)
		return new_node(data);

	if (data < root->data)
		root->left = insert(root->left, data);
	
	else
		root->right = insert(root->right, data);

	return root;
}

struct node* min_node(struct node* node) {
	while (node->left != NULL)
		node = node->left;
	return node;
}
struct node* delete_node(struct node* root, int data) {
	if (root == NULL)
		return root;
	if (data < root->data)
		root->left = delete_node(root->left, data);
	else if (data > root->data)
		root->right = delete_node(root->right, data);
	else {
		//only one child
		if (root->left == NULL) {
			struct node* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			struct node* temp = root->left;
			free(root);
			return temp;
		}
		// two children
		struct node* temp = min_node(root->right);
		root->data = temp->data;
		//delete inorder successor
		root->right = delete_node(root->right, temp->data);
	}
	return root;
}

int main() {
	struct node* root = NULL;
	root = insert(root, 8);
	root = insert(root, 3);
	root = insert(root, 1);
	root = insert(root, 6);
	root = insert(root, 7);
	root = insert(root, 10);
	root = insert(root, 14);
	root = insert(root, 4);

	printf("Inorder traversal: ");
	inorder(root);

	printf("\nAfter deleting 10\n");
	root = delete_node(root, 10);
	printf("Inorder traversal: ");
	inorder(root);
}
