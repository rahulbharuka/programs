#include<stdio.h>
#include<malloc.h>


void mergeArrays(int A[], int l, int m, int r, int B[])
{
	int i = l, j = m + 1;
	int k = l;

	while ((i <= m) && (j <= r))
	{
		if (B[i] <= B[j])
		{
			A[k] = B[i];
			i++;
		}
		else
		{
			A[k] = B[j];
			j++;
		}
		k++;
	}

	while (i <= m)
	{
		A[k] = B[i];
		k++;
		i++;
	};

	while (j <= r)
	{
		A[k] = B[j];
		k++;
		j++;
	};

	for (int i = l; i <= r; i++)
		B[i] = A[i];

}

void mergeSort(int A[], int l, int r, int B[])
{
	int m;

	if (l == r)
		return;

	if (l < r)
	{
		m = l + (r - l)/2;
		mergeSort(A, l, m, B);
		mergeSort(A, m+1, r, B);
		mergeArrays(A, l, m, r, B);
	}

}

int main()
{
	int n;
	scanf("%d", &n);

	int *A = (int *) malloc(sizeof(int) * n);
	int *B = (int *) malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
		B[i] = A[i];
	}

	mergeSort(A, 0, n-1, B);

	printf("Sorted Array: ");
	for (int i = 0; i < n; i++)
		printf("%d ", A[i]);

	printf("\n");
	free(A);
	free(B);
}
