#ifndef _HEAP_H_
#define _HEAP_H_

#include <stdbool.h>

#define SWAP(a, b)\
{\
	int temp;\
	temp = a;\
	a = b;\
	b = temp;\
}\

typedef struct _Heap
{
	int *arr;
	int size;
	int capacity;
	bool (*comparator_func) (int child, int parent);
} Heap;

Heap* createHeap(int N);
bool maxHeapComparator(int a, int b);
bool minHeapComparator(int a, int b);
int getParent(int inx);
int getLeftChild(int inx);
int getRightChild(int inx);
int topHeap(Heap *heap);
void heapify(Heap *heap, int inx);
int extractTopHeap(Heap *heap);
void buildHeap(Heap *heap);
void freeHeap(Heap *heap);

#endif
