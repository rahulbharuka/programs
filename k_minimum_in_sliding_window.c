#include<stdio.h>
#include<stdlib.h>
#include "deque.h"

void find_k_min_in_sliding_window(int *arr, int n, int k)
{
	int i;
	Deque *q = createDeque(k);
	for (i = 0; i < k; i++)
	{
		while(!isEmpty(q) && (arr[i] < arr[getRear(q)]))
			deleteRear(q);

		insertRear(q, i);
	}

	for( ; i < n; i++)
	{
		printf("%d ", arr[getFront(q)]);

		while(!isEmpty(q) && (getFront(q) <= (i - k)))
			deleteFront(q);

		while(!isEmpty(q) && (arr[i] < arr[getRear(q)]))
			deleteRear(q);

		insertRear(q, i);
	}

	printf("%d\n", arr[getFront(q)]);
}

int main()
{
	int n, k;
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	int *arr = (int *) malloc(sizeof(int) * n);
	printf("Enter %d elements: ", n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	printf("Now enter the size of the window: ");
	scanf("%d", &k);
	find_k_min_in_sliding_window(arr, n, k);
	free(arr);
}
