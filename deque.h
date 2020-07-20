#ifndef _DEQUE_H_
#define _DEQUE_H_

typedef struct _Deque
{
	int *arr;
	int front;
	int rear;
	int size;
	int capacity;
} Deque;

Deque* createDeque(int N);
void freeDeque(Deque *q);
int isFull(Deque *q);
int isEmpty(Deque *q);
void insertRear(Deque *q, int val);
void insertFront(Deque *q, int val);
int deleteFront(Deque *q);
int deleteRear(Deque *q);
int getFront(Deque *q);
int getRear(Deque *q);

#endif
