#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "deque.h"

Deque* createDeque(int N)
{
	Deque *q = (Deque *) malloc(sizeof(Deque));
	q->arr = (int *) malloc(sizeof(int) * N);
	q->front = q->rear = -1;
	q->size = 0;
	q->capacity = N;
	return q;
}

void freeDeque(Deque *q)
{
	free(q->arr);
	free(q);
}

int isFull(Deque *q)
{
	return (q->size == q->capacity);
}

int isEmpty(Deque *q)
{
	return !q->size;
}

void insertRear(Deque *q, int val)
{
	if (isFull(q))
		return;

	if (q->rear == -1)
	{
		q->rear = 0;
		q->front = 0;
	}
	else if (q->rear == q->capacity - 1)
		q->rear = 0;
	else
		q->rear += 1;
		
	q->arr[q->rear] = val;
	q->size += 1;
}

void insertFront(Deque *q, int val)
{
	if (isFull(q))
		return;

	if (q->front == -1)
	{
		q->front = 0;
		q->rear = 0;
	}
	else if (q->front == 0)
		q->front = q->capacity - 1;
	else
		q->front -= 1;
	
	q->arr[q->front] = val;
	q->size += 1;
}

int deleteFront(Deque *q)
{
	if (isEmpty(q))
		return INT_MIN; 

	int item = q->arr[q->front];
	q->size -= 1;
	
	if (q->size == 0)
	{
		q->front = -1;
		q->rear = -1;
	}
	else if (q->front == q->capacity - 1)
		q->front = 0;
	else
		q->front += 1;

	return item;
}

int deleteRear(Deque *q)
{
	if (isEmpty(q))
		return INT_MIN; 

	int item = q->arr[q->rear];
	q->size -= 1;
	
	if (q->size == 0)
	{
		q->front = -1;
		q->rear = -1;
	}
	else if (q->rear == 0)
		q->rear = q->capacity - 1;
	else
		q->rear -= 1;

	return item;
}

int getFront(Deque *q)
{
	if (isEmpty(q))
		return INT_MIN;

	return q->arr[q->front];
}

int getRear(Deque *q)
{
	if (isEmpty(q))
		return INT_MIN;

	return q->arr[q->rear];
}
