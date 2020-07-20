#include <stdio.h>
#include <stdlib.h>

typedef struct _LinkedList
{
    int val;
    struct _LinkedList *next;
    struct _LinkedList *previous;
} LinkedList;


int main() {
    int i, N;
    scanf("%d", &N);
    LinkedList *head = NULL, *ptr = NULL, *prev, *median = NULL, *temp;
    for (i = 0; i < N; i++)
    {
        LinkedList *node = (LinkedList *) malloc(sizeof(LinkedList));
        scanf("%d", &node->val);
        
        prev = NULL;
        ptr = head;
        while (ptr && (ptr->val <= node->val))
        {
            prev = ptr;
            ptr = ptr->next;
        }
        
        if (head == NULL)
	{
	    head = node;	
	    node->next = NULL;
	    node->previous = NULL;
	    median = head;
	}
	else if (prev == NULL)
        {
            node->next = head;
	    head->previous = node;
	    head = node;
        }
        else
        {
            prev->next = node;
	    node->previous = prev;
            node->next = ptr;
	    if (ptr)
	    	ptr->previous = node;
        }
        
	if (i >= 2)
	{
	    if ((i%2 == 0) && (node->val >= median->val))
	    {
	    	median = median->next;
	    }
	    else if ((i%2) && (node->val < median->val)) 
	    {
	    	median = median->previous;
	    }

	}

        if (i%2 == 0)
            printf("%d\n", median->val);
        else
            printf("%d\n", (median->val + median->next->val)/2);
    }
	return 0;
}
