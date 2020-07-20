#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
typedef struct node
{
	int data;
	struct node* left;
	struct node* right;
} Node;

bool checkBST(Node* root, int minValue, int maxValue) {
	if (root == NULL) {
		return true;
	}

	if (root->data < minValue || root->data > maxValue) {
		return false;
	}

	return (    checkBST(root->left, minValue, root->data - 1) 
			&&  checkBST(root->right, root->data + 1, maxValue)
	       );
}

bool isBST(Node* root) {
	return checkBST(root, 0, 10000);
}

struct node* newNode(int data)
{
	struct node* node = (struct node*)
		malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return(node);
}

/* Driver program to test above functions*/
int main()
{
	struct node *root = newNode(4);
	root->left        = newNode(2);
	root->right       = newNode(5);
	root->left->left  = newNode(1);
	root->left->right = newNode(3); 

	if(isBST(root))
		printf("Is BST\n");
	else
		printf("Not a BST");

	return 0;
}  
