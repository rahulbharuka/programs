#include <stdio.h>
#include "heap.h"

int main()
{
	int N;
	printf("Enter maximum capacity of the heap: ");
	scanf("%d", &N);
	int *Num;
		
	Heap *maxHeap = createHeap(N);
	maxHeap->comparator_func = (void *) &maxHeapComparator;

	printf("Now enter the elements: ");
	for (int i = 0; i < N; i++)
		scanf("%d", &maxHeap->arr[i]);

	maxHeap->size = N;
	buildHeap(maxHeap);
	printf("Heap Top = %d\n", topHeap(maxHeap));
	freeHeap(maxHeap);
	return 0;
}
