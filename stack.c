#include "stack.h"
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

Stack* createStack(int N)
{
	Stack *s = (Stack *) malloc(sizeof(Stack));
	s->arr = (int *) malloc(sizeof(int) * N);
	s->capacity = N;
	s->top = -1;
	return s;
}

bool isFull(Stack *s)
{
	return (s->top == (s->capacity - 1));
}

bool isEmpty(Stack *s)
{
	return (s->top == -1);
}

int peek(Stack *s)
{
	if (isEmpty(s))
		return INT_MIN;
	
	return s->arr[s->top];
}

void push(Stack *s, int val)
{
	if (isFull(s))
		return;	// stack is full.

	s->arr[++s->top] = val;
}

int pop(Stack *s)
{
	if (isEmpty(s))
		return INT_MIN;	// stack is empty

	return s->arr[s->top--];
}

void freeStack(Stack *s)
{
	free(s->arr);
	free(s);
}
