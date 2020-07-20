#include<stdio.h>
#include<stdlib.h>

//Q2 : [ Double linked circular list ] in [ ordered fashion ] 

typedef struct _Node
{
	int val;
	struct _Node *prev;
	struct _Node *next;
} Node;


int insert(Node **head, int val)
{
	Node *n = (Node *) malloc(sizeof(Node));
	if (n == NULL)
		return -1;

	n->val = val;
	n->prev = NULL;
	n->next = NULL;

	if (*head == NULL)
	{
		n->next = n;
		n->prev = n;
		*head = n;
		return 0;
	}


	Node *ptr = *head;
	while(ptr && (ptr->next != *head))
	{
		if (ptr->val < val)
			ptr = ptr->next;
		else
			break;
	}

	if (ptr->next == *head)
	{
		ptr->next = n;
		n->prev = ptr;
		n->next = *head;
		(*head)->prev = n;

		if (val < ptr->val)
			*head = n;
	}
	else
	{
		ptr->prev->next = n;
		n->prev = ptr->prev;
		n->next = ptr;
		ptr->prev = n;
	}
	return 0;
}

void print_DLL(Node *head)
{
	Node *ptr = head;
	do
	{
		printf("%d ", head->val);
	} while(ptr && (ptr != head));
}


int main()
{
	int n, val;
	Node *head = NULL;
	insert(&head, 1);
	insert(&head, 2);
	insert(&head, 4);
	print_DLL(head);
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &val);
		insert(&head, val);
		print_DLL(head);
	}

}
