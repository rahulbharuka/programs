#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

/*

A bit of a background: Kadane's algorithm is based on splitting up the set of possible solutions into mutually exclusive (disjoint) sets. We exploit the fact that any solution (i.e., any member of the set of solutions) will always have a last element i (this is what is meant by "sum ending at position i). Thus, we simply have to examine, one by one, the set of solutions whose last element's index is 1, the set of solutions whose last element's index is 2, then 3, and so forth to n. It turns out that this process can be carried out in linear time.

Kadane's algorithm begins with a simple inductive question: if we know the maximum subarray sum ending at position i (call this B_i, what is the maximum subarray sum ending at position i + 1 (equivalently, what is B_i+1 ? The answer turns out to be relatively straightforward: either the maximum subarray sum ending at position i + 1 includes the maximum subarray sum ending at position i as a prefix, or it doesn't (equivalently, B_i+1 = max(A_i+1, A_i+1 + B_i), where A_i+1 is the element at index i + 1).

Note: with a bit of reasoning you will see that max_so_far is equal to max( B_0, B_1, B_2, ..., B_i).

Time Complexity = O(n)
*/

int findMaxContiguousSumArray(int *arr, int n, int *start, int *end)
{
	int s = 0, max_so_far = INT_MIN, max_ending_here = 0;

	for (int i = 0; i < n; i++)
	{
		max_ending_here += arr[i];

		if (max_so_far < max_ending_here)
		{
			max_so_far = max_ending_here;
			*start = s;
			*end = i;
		}

		if (max_ending_here < 0)
		{
			max_ending_here = 0;
			s = i + 1;
		}
	}

	return max_so_far;
}

int main()
{
	int n, sum, start = 0, end = 0;
	printf("Enter the number of elements in array: ");
	scanf("%d", &n);
	printf("Now input %d elements separated by space:\n", n);
	
	int *arr = malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	sum = findMaxContiguousSumArray(arr, n, &start, &end);
	printf("Maximum contiguous sum is %d. It starts at index %d and ends at index %d.\n", sum, start, end);
}
