#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

int main()
{
	int C, N;
	printf("Enter maximum capacity of the stack: ");
	scanf("%d", &C);
	Stack *s = createStack(C);
	printf("Enter the number of elements to be pushed to the stack [ < capacity]: ");
	scanf("%d", &N);

	if (N > C)
	{	
		printf("Invalid input!\n");
		freeStack(s);
		exit(0);
	}

	int val;
	printf("Now enter the elements: ");
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &val);
		push(s, val);
	}

	printf("Content of the stack: ");
	while (!isEmpty(s))
		printf("%d ", pop(s));

	printf("\n");
	freeStack(s);
}
