#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

#define SIZE 26

typedef struct trieNode {
	struct trieNode *children[SIZE];
	int count;
} Node;

Node* createNode() {
	Node *node = (Node *) malloc(sizeof(Node));
	for (int i = 0; i < SIZE; i++)
		node->children[i] = NULL;

	node->count = 0;
	return node;
}

void addName(Node *root, char *name) {
	if (!root || !name)
		return;

	int len = strlen(name), inx;
	Node *node = root;
	for (int i = 0; i < len; i++) {
		inx = name[i] - 'a';
		if (node->children[inx] == NULL)
			node->children[inx] = createNode();

		node = node->children[inx];
		node->count += 1;
	}
}

int findPattern(Node *root, char *pattern) {
	if (!root || !pattern)
		return 0;

	int len = strlen(pattern), inx;
	Node *node = root;
	for (int i = 0; i < len; i++) {
		inx = pattern[i] - 'a';
		if (node->children[inx] != NULL)
			node = node->children[inx];
		else
			return 0;
	}
	return node ? node->count : 0;
}

int main(){
	int n; 
	scanf("%d",&n);
	Node *root = createNode();
	for(int a0 = 0; a0 < n; a0++){
		char* op = (char *)malloc(512000 * sizeof(char));
		char* contact = (char *)malloc(512000 * sizeof(char));
		scanf("%s %s",op,contact);
		if (strcmp(op, "add") == 0)
			addName(root, contact);
		else if (strcmp(op, "find") == 0)
			printf("%d\n", findPattern(root, contact));
	}
	return 0;
}
