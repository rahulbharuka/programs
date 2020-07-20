#ifndef _STACK_H_
#define _STACK_H_

#include<stdbool.h>

typedef struct _Stack
{
	int *arr;
	int capacity;
	int top;
} Stack;

Stack* createStack(int N);
bool isFull(Stack *s);
bool isEmpty(Stack *s);
int peek(Stack *s);
void push(Stack *s, int val);
int pop(Stack *s);
void freeStack(Stack *s);

#endif
