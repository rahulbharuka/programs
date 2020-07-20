#ifndef _QUEUE_H_
#define _QUEUE_H_

typedef struct _Queue
{
	int *arr;
	int front;
	int rear;
	int size;
	int capacity;
} Queue;

Queue* createQueue(int N);
void freeQueue(Queue *q);
int isFull(Queue *q);
int isEmpty(Queue *q);
void enqueue(Queue *q, int val);
int dequeue(Queue *q);
int getFront(Queue *q);

#endif
