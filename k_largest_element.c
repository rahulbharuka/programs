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
{\
	int temp;\
	temp = a;\
	a = b;\
	b = temp;\
}\

int topHeap(Heap *heap)
{
	return heap->arr[0];
}

/* This function will heapify tree rooted at arr[inx]. */
void heapify(Heap *heap, int inx)
{
	int left = getLeftChild(inx);
	int right = getRightChild(inx);
	int minmax = inx;

	if ((left < heap->size) && heap->comparator_func(heap->arr[left], heap->arr[minmax]))
		minmax = left;

	if ((right < heap->size) && heap->comparator_func(heap->arr[right], heap->arr[minmax]))
		minmax = right;

	if (minmax != inx)
		SWAP(heap->arr[inx], heap->arr[minmax]);

	if (minmax != inx)
		heapify(heap, minmax);
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

/* Build the heap. For building heap from an existing array, only bottom-up method should be used.
 * This is a bottom-up approach as we starting lower in the tree and then going up in the tree.
 * Time complexity: O(n)
 */
void buildHeap(Heap *heap)
{
	for (int i = (heap->size - 1)/2; i >= 0; i--)
		heapify(heap, i);
}

void printTopK(Heap *heap, int K)
{
	for (int i = 0; i < K; i++)
		printf("%d ", extractTopHeap(heap));

	printf("\n");
}

int main()
{
	int T, N, K;
	scanf("%d", &T);
	int *Num;

	for (int t = 0; t < T; t++)
	{
		scanf("%d %d", &N, &K);
		Heap *maxHeap = createHeap(N);
		maxHeap->comparator_func = (void *) &maxHeapComparator;
		
		for (int i = 0; i < N; i++)
			scanf("%d", &maxHeap->arr[i]);

		maxHeap->size = N;
		buildHeap(maxHeap);
		printTopK(maxHeap, K);
		free(maxHeap->arr);
		free(maxHeap);
	}
	return 0;
}
