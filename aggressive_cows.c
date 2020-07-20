#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).

His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?

Input:
t – the number of test cases, then t test cases follows.
* Line 1: Two space-separated integers: N and C
* Lines 2..N+1: Line i+1 contains an integer stall location, xi

Output:
For each test case output one integer: the largest minimum distance.


*/

int partition(int arr[], int lo, int hi)
{
	int pivot = arr[lo], tmp;
	int i = lo - 1, j = hi + 1;

	while (1)
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

		tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}
}

void quicksort(int arr[], int lo, int hi)
{
	int p;

	if (lo < hi)
	{
		p = partition(arr, lo, hi);
		quicksort(arr, lo, p);
		quicksort(arr, p+1, hi);
	}
}

bool isPossible(int arr[], int N, int Cows, int dist)
{
	int c = 1, prev = arr[0];

	for (int i = 1; i < N; i++)
	{
		if ((arr[i] - prev) >= dist)
		{
			c++;
			if (c == Cows)
				return true;

			prev = arr[i];
		}
	}

	return false;
}

int main(void)
{
	int T, N, C, *stall, c, start, end, mid;
	scanf("%d", &T);
	
	for (int i = 0; i < T; i++)
	{
		scanf("%d", &N);
		scanf("%d", &C);
		stall = (int *) malloc(sizeof(int) * N);
		for (int j = 0; j < N; j++)
			scanf("%d", &stall[j]);
			
		quicksort(stall, 0, N-1);
		start = 0;
		end = stall[N-1] - stall[0] + 1;
		while ((end - start) > 1)
		{
			mid = (start + end)/2;

			if (isPossible(stall, N, C, mid))
				start = mid;
			else
				end = mid;

		}

		printf("%d\n", start);
	}
	
	return 0;
}
