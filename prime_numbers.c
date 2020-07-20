#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>

/* 
	Time complexity: O(n log log n)
	Explanation: Outer loop takes O(log log n) time and inner loop takes O(n0 time.

*/
int main()
{
	int n;
	printf("Find all prime numbers smaller than: ");
	scanf("%d", &n);
	bool *prime = (bool *) malloc(sizeof(bool) * (n+1));
	memset(prime, true, n+1);
	prime[0] = prime[1] = false;

	for (int i = 2; i < sqrt(n); i++)
	{
		if (prime[i])
		{
			for (int j = i*i; j < n; j += i)
				prime[j] = false;
		}
	}

	printf("Prime numbers: ");
	for (int i = 2; i < n; i++)
		if (prime[i])
			printf("%d ", i);

	printf("\n");
	free(prime);
}
