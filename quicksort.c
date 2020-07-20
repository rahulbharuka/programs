#include<stdio.h>
#include<stdlib.h>

#define SWAP(a, b)\
{\
	int tmp;\
	tmp = a;\
	a = b;\
	b = tmp;\
}\

void printArr(int arr[], int lo, int hi)
{
	for (int i = lo; i <= hi; i++)
		printf("%d ", arr[i]);
	
	printf("\n");
}

/* This function will partition arr[] such that
 * (1) arr[lo...p] <= pivot
 * (2) arr[p+1...hi] >= pivot.
 * NOTE: After partition, 'pivot' may belong any of these sub-arrays and it's position need not be final.
 */
int partition(int arr[], int lo, int hi)
{
	int pivot = arr[lo];
	//int pivot = arr[hi];

	int i = lo - 1;
	int j = hi + 1;
	while (1) 
	{
		/* 'Do-While' is needed here to increase values of 'i' and 'j' for the next iteration.
		 * Otherwise, it may loop forever and continuously swap a[i] and a[j].
		 * If you want to use 'While', then do i++; j--; after SWAP.
		 */
		do
		{
			i++;
		} while (arr[i] < pivot);	// In the first iteration a[i] will be pointing to the pivot element. 

		do
		{
			j--;
		}
		while (arr[j] > pivot);

		if (i >= j)
			return j;
			//when pivot = arr[hi] use - return i;

		SWAP(arr[i], arr[j]);
	}
}

void quicksort(int arr[], int lo, int hi)
{
	int p;

	if (lo < hi)
	{
		p = partition(arr, lo, hi);
		//printf("p=%d lo=%d hi=%d\t", p, lo, hi);
		//printArr(arr, lo, hi);
		/* The pivot's final location is not necessarily at the index 'p' that was returned.
		 * That's why we need to include 'p' in the first recursive call.
		 */
		quicksort(arr, lo, p);
		quicksort(arr, p+1, hi);
		
		/* When pivot = arr[hi] use -
		 *	quicksort(arr, lo, p-1);
		 *	quicksort(arr, p, hi);
		 * Reason:
		 	(1) when pivot = arr[lo], lo <= p < hi
			(2) when pivot = arr[hi], lo < p <= hi
		 *
		 */
	}
}

int main()
{
	int N, *arr;
	scanf("%d", &N);
	arr = (int *) malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	quicksort(arr, 0, N-1);
	printf("Sorted Array: ");
	printArr(arr, 0, N-1);
}
