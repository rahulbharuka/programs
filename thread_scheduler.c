#include<stdio.h>
#include<stdlib.h>

#define SWAP(a, b)\
do{\
	int tmp = a;\
	a = b;\
	b = tmp;\
} while(0);\

typedef struct _Job
{
	int id;
	int time;
} Job;

typedef struct _Heap
{
	Job *arr;
	int size;
	int capacity;
} Heap;

Heap* createHeap(int N)
{
	Heap *h = (Heap *) malloc(sizeof(Heap));
	h->arr = (Job *) calloc(N, sizeof(Job));
	h->size = 0;
	h->capacity = N;
}

void freeHeap(Heap *h)
{
	free(h->arr);
	free(h);
}

int leftChild(int inx)
{
	return (2 * inx + 1);
}

int rightChild(int inx)
{
	return (2 * inx + 2);
}

int parent(int inx)
{
	return (inx - 1)/2;
}

void heapify(Heap *h, int inx)
{
	int min_inx = inx;
	int linx = leftChild(inx);
	int rinx = rightChild(inx);
	int tmp1, tmp2;

	if ((linx < h->capacity) && (h->arr[linx].time < h->arr[min_inx].time))
		min_inx = linx;

	if ((rinx < h->capacity) && (h->arr[rinx].time < h->arr[min_inx].time))
		min_inx = rinx;

	if (min_inx != inx)
	{
		tmp1 = h->arr[inx].id;
		h->arr[inx].id = h->arr[min_inx].id;
		h->arr[min_inx].id = tmp1;

		tmp2 = h->arr[inx].time;
		h->arr[inx].time = h->arr[min_inx].time;
		h->arr[min_inx].time = tmp2;

		heapify(h, min_inx);
	}
}

void thread_scheduler_using_heap(int N, int M, int *Time)
{
	Heap *h = createHeap(N);
	for (int i = 0; i < N; i++)
		h->arr[i].id = i;

	printf("Using Heap {theadId, waitTime}: ");
	for (int i = 0; i < M; i++)
	{
		printf("{%d,%d}, ", h->arr[0].id, h->arr[0].time);
		h->arr[0].time += Time[i];
		heapify(h, 0);
	}

	printf("\n\n");
	freeHeap(h);
}

int find_min(int *Thread, int N)
{
	int min = 0;
	for (int i = 1; i < N; i++)
		if ( Thread[min] > Thread[i])
			min = i;

	return min;
}

void thread_scheduler(int N, int M, int *Time)
{
	int *Thread = (int *) calloc(sizeof(int), N);
	int next_thread = 0;
	printf("{theadId, waitTime}: ");
	for (int i = 0; i < M; i++)
	{
		next_thread = find_min(Thread, N); 
		printf("{%d,%d}, ", next_thread, Thread[next_thread]);
		Thread[next_thread] += Time[i];
	}

	printf("\n\n");
	free(Thread);
}

int partition(int *arr, int lo, int hi)
{
	int pivot = arr[lo];
	int i = lo - 1, j = hi + 1;

	while(1)
	{
		do
		{
			i++;
		} while (arr[i] < pivot);

		do
		{
			j--;
		} while (arr[j] > pivot);

		if (i >= j)
			return j;

		SWAP(arr[i], arr[j]);
	}
}

void quicksort(int *arr, int lo, int hi)
{
	if (lo < hi)
	{
		int p = partition(arr, lo, hi);
		quicksort(arr, lo, p);
		quicksort(arr, p+1, hi);
	}
}

void optimal_thread_scheduler(int N, int M, int *Time)
{
	quicksort(Time, 0, M-1);
	printf("Optimum job execution: ");
	for (int i = 0; i < M; i++)
		printf("%d ", Time[i]);

	printf("\n");
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	int *Time = (int *)calloc(sizeof(int), M);
	for (int i = 0; i < M; i++)
		scanf("%d", &Time[i]);

	thread_scheduler(N, M, Time);
	thread_scheduler_using_heap(N, M, Time);
	optimal_thread_scheduler(N, M, Time);
	free(Time);
}
