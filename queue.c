#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue* createQueue(int N)
{
	Queue *q = (Queue *) malloc(sizeof(Queue));
	q->arr = (int *) malloc(sizeof(int) * N);
	q->front = q->rear = q->size = 0;
	q->capacity = N;
	return q;
}

void freeQueue(Queue *q)
{
	free(q->arr);
	free(q);
}

int isFull(Queue *q)
{
	return (q->size == q->capacity);
}

int isEmpty(Queue *q)
{
	return !q->size;
}

void enqueue(Queue *q, int val)
{
	if (isFull(q))
		return;
	
	q->arr[q->rear] = val;
	q->size += 1;
	q->rear += 1;
	if (q->rear == q->capacity)
		q->rear = 0;
		
}

int dequeue(Queue *q)
{
	if (isEmpty(q))
		return -1; 

	int item = q->arr[q->front];
	q->size -= 1;
	q->front += 1;
	if (q->front == q->capacity)
		q->front = 0;

	return item;
}

int getFront(Queue *q)
{
	if (isEmpty(q))
		return -1;

	return q->arr[q->front];
}

