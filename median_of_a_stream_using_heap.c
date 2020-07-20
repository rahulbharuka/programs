#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _Heap
{
	int *arr;
	int size;
	int capacity;
	bool (*comparator_func) (int child, int parent);
} Heap;

Heap* createHeap(int N)
{
	Heap *h = (Heap *) malloc(sizeof(Heap));
	h->arr = (int *) malloc(sizeof(int) * N);
	h->size = 0;
	h->capacity = N;
	return h;
}

int getHeapSizeDiff(int l, int r)
{
	if (l == r)
		return 0;
	else
		return (l > r) ? 1 : -1;
}

bool maxHeapComparator(int a, int b)
{
	return a > b;
}

bool minHeapComparator(int a, int b)
{
	return a < b;
}

int getParent(int inx)
{
	if (inx <= 0)
		return -1;
	else
		return (inx - 1)/2;
}

int getLeftChild(int inx)
{
	return (2 * inx + 1);
}

int getRightChild(int inx)
{
	return (2 * inx + 2);
}

#define SWAP(a, b)\
	int temp;\
	temp = a;\
	a = b;\
	b = temp;\

/* This function will heapify tree routed at arr[inx].
 * This function assumes that except arr[inx], rest of the array elements follows the min/max heap property.
 */
void heapify(Heap *heap, int inx)
{
	int left = getLeftChild(heap->arr[inx]);
	int right = getRightChild(heap->arr[inx]);
	int minmax;

	if ((left < heap->size) && heap->comparator_func(heap->arr[left], heap->arr[inx]))
		minmax = left;
	else
		minmax = inx;

	if ((right < heap->size) && heap->comparator_func(heap->arr[right], heap->arr[minmax]))
		minmax = right;

	if (minmax != inx)
	{
		SWAP(heap->arr[inx], heap->arr[minmax]);
		heapify(heap, minmax);
	}
}

/* This is a top-down implementation as the tree is built from top to down.
 * This is not optimal as its complexity is O(n log n). For bottom-up approach time complexity is O(n).
 * However, its appropriate in this problem for current median computation.
 */
bool insertHeap(Heap *heap, int num)
{
	bool ret = false;
	if (heap->size < heap->capacity)
	{
		heap->arr[heap->size] = num;
		heap->size += 1;

		int inx = heap->size - 1;
		int pinx = getParent(inx);
		while ((pinx >= 0) && heap->comparator_func(heap->arr[inx], heap->arr[pinx]))
		{
			SWAP(heap->arr[inx], heap->arr[pinx]);
			inx = pinx;
			pinx = getParent(inx);
		}
		ret = true;
	}

	return ret;
}

int topHeap(Heap *heap)
{
	return heap->arr[0];
}

int extractTopHeap(Heap *heap)
{
	int top = -1;
	if (heap->size > 0)
	{
		top = topHeap(heap);
		SWAP(heap->arr[0], heap->arr[heap->size - 1]);
		heap->size -= 1;
		heapify(heap, 0);
	}
	return top;
}


int getMedian(int num, int curMedian, Heap* maxHeap, Heap* minHeap)
{
	int diff;
	diff = getHeapSizeDiff(maxHeap->size, minHeap->size);

	switch(diff)
	{
		case 1: /* Left heap (maxHeap) has more number of elements. */
			if (num < curMedian)
			{
				insertHeap(minHeap, extractTopHeap(maxHeap));
				insertHeap(maxHeap, num);
			}
			else
				insertHeap(minHeap, num);

			curMedian = (topHeap(maxHeap) + topHeap(minHeap))/2;
			break;
		case 0: /* Both left and right heaps have equal number of elements. */
			if (num < curMedian)
			{
				insertHeap(maxHeap, num);
				curMedian = topHeap(maxHeap);
			}
			else
			{
				insertHeap(minHeap, num);
				curMedian = topHeap(minHeap);
			}
			break;
		case -1: /* Right heap (minHeap) has more number of elements. */
			if (num < curMedian)
				insertHeap(maxHeap, num);
			else
			{
				insertHeap(maxHeap, extractTopHeap(minHeap));
				insertHeap(minHeap, num);
			}

			curMedian = (topHeap(maxHeap) + topHeap(minHeap))/2;
			break;
	}

	return curMedian;
}

void printMedian(int Num[], int N)
{
	int i, curMedian = 0;
	Heap *maxHeap = createHeap(N);
	maxHeap->comparator_func = (void *) &maxHeapComparator;
	Heap *minHeap = createHeap(N);
	minHeap->comparator_func = (void *) &minHeapComparator;

	//printf("\n");
	for (i = 0; i < N; i++)
	{
		curMedian = getMedian(Num[i], curMedian, maxHeap, minHeap);
		printf("%d\n", curMedian);
	}

	free(maxHeap->arr);
	free(maxHeap);

	free(minHeap->arr);
	free(minHeap);
}

int main()
{
	int i, N;
	scanf("%d", &N);
	int *Num = (int *) malloc(sizeof(int) * N);

	for (i = 0; i < N; i++)
		scanf("%d", &Num[i]);

	printMedian(Num, N);
	free(Num);
	return 0;
}
