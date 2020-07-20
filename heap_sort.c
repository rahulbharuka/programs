#include<stdio.h>
#include<malloc.h>

#define SWAP(a, b)\
{\
	int tmp = a;\
	a = b;\
	b = tmp;\
}\

int getLeftChild(int inx)
{
	return (2 * inx + 1);
}

int getRightChild(int inx)
{
	return (2 * inx + 2);
}

void heapify(int A[], int sz, int inx)
{
	int max = inx;
	int left = getLeftChild(inx);
	int right = getRightChild(inx);

	if ((left < sz) && (A[left] > A[max]))
		max = left;

	if ((right < sz) && (A[right] > A[max]))
		max = right;

	if (max != inx)
		SWAP(A[max], A[inx]);

	if (max != inx)
		heapify(A, sz, max);
}

void heapSort(int A[], int n)
{
	for (int i = n/2 - 1; i >= 0; i--)
		heapify(A, n, i);

	for (int i = n-1; i >= 0; i--)
	{
		SWAP(A[0], A[i]);
		heapify(A, i, 0);
	}
}

int main ()
{
	int n;
	scanf("%d", &n);

	int *A = (int *) malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);

	heapSort(A, n);
	
	printf("Sorted Array: ");
	for (int i = 0; i < n; i++)
		printf("%d ", A[i]);
	
	printf("\n");

	free(A);
}
