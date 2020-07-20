#include<stdio.h>
#include<malloc.h>
#include<limits.h>

#define MAX(a, b) (a > b ? a : b)

// Refer: https://brilliant.org/wiki/egg-dropping/

int solveEggDropping(int n, int k)
{
	int **DropCount = (int **) calloc(sizeof(int *), n+1);
	for (int i = 0; i <= n; i++)
		DropCount[i] = (int *) calloc(sizeof(int), k+1);

	for (int i = 1; i <= n; i++)
		DropCount[i][1] = 1;	// Only one trial is needed when k = 1.
		
	for (int j = 1; j <= k; j++)
		DropCount[1][j] = j;	// i trials will be needed when n = 1

	/* NOTE:
		1. Not initializing (DropCount[i][0] = 0) here because calloc already took care of it.
		2. Similarly (DropCount[0][j] = 0) initialization is also not needed.
	*/

	int res;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 2; j <= k; j++)
		{
			DropCount[i][j] = INT_MAX;
			for (int x = 1; x <= j; x++)	// x corresponds to floor where first egg (out of j) will be dropped.
			{
				res = MAX(DropCount[i-1][x-1], DropCount[i][j-x]) + 1;	// MAX is used to know the worst case.
				if (res < DropCount[i][j])
					DropCount[i][j] = res;
			}
		}
	}

	return DropCount[n][k];	
}

int main()
{
	int n, k;
	printf("Enter the number of eggs: ");
	scanf("%d", &n);
	printf("Enter the number of floors: ");
	scanf("%d", &k);

	int res = solveEggDropping(n, k);
	printf("Minimum %d trails are needed in the worst case for above combination.\n", res);

}
