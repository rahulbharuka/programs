/*

Given a 2D matrix with integer values identify the longest increasing path starting from any cell in the matrix. From a cell (x,y) you can jump to (x-1,y), (x+1,y), (x,y-1) and (x,y+1).  (This was asked in phone screening)

Eg., For the matrix below the longest increasing path would be 0 -> 1 -> 2 -> 4 -> 5 -> 8 -> 9

4 5 8 9 2

2 2 9 7 3

1 0 3 -1 2 

5 6 7 -2 9

*/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#include<stdbool.h>

int r[] = {-1, 0, 1, 0};
int c[] = {0, 1, 0, -1};

bool isSafe(int M, int N, int r, int c)
{
	if ((r < 0) || (c < 0) || (r >= M) || (c >= N))
		return false;

	return true;
}

void dfs(int **A, int M, int N, int i, int j, int **PathLen)
{
	int row, col;
	int len = 1;
	for (int k = 0; k < 4; k++)
	{
		row = i + r[k];
		col = j + c[k];

		if (isSafe(M, N, row, col))
		{
			if ((PathLen[row][col] == INT_MIN) && (A[row][col] > A[i][j]))
				dfs(A, M, N, row, col, PathLen);

			if((A[row][col] > A[i][j]) && ((PathLen[row][col]+1) > len))
				len = PathLen[row][col] + 1;

		}
	}

	PathLen[i][j] = len;
}

int get_longest_increasing_path(int **A, int M, int N, int *rinx, int *cinx, int **PathLen)
{
	int maxLen = INT_MIN;
	
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (PathLen[i][j] == INT_MIN)
				dfs(A, M, N, i, j, PathLen);

			if (PathLen[i][j] > maxLen)
			{
				maxLen = PathLen[i][j];
				*rinx = i;
				*cinx = j;
			}
		}
	}

	return maxLen;
}

void print_longest_increasing_path(int **A, int M, int N, int rinx, int cinx, int **PathLen)
{
	int row, col;
	
	printf("[%d:(%d, %d)]", A[rinx][cinx], rinx, cinx);
	
	for (int k = 0; k < 4; k++)
	{
		row = rinx + r[k];
		col = cinx + c[k];

		if (isSafe(M, N, row, col) && ((PathLen[row][col]+1) == PathLen[rinx][cinx]))
		{
			printf(" --> ");
			print_longest_increasing_path(A, M, N, row, col, PathLen);
			break;
		}
	}
}

int main()
{
	int M, N, rinx, cinx;
	printf("Enter dimensions of input matrix: ");
	scanf("%d %d", &M, &N);
	int **A = (int **) malloc(sizeof(int*) * M);
	for (int i = 0; i < M; i++)
		A[i] = (int *) malloc(sizeof(int) * N);

	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &A[i][j]);

	int **PathLen = (int **) malloc(sizeof(int *) * M);
	for (int i = 0; i < M; i++)
	{
		PathLen[i] = (int *) malloc(sizeof(int) * N);
		for (int j = 0; j < N; j++)
			PathLen[i][j] = INT_MIN;
	}

/*
	printf("Input Matrix:\n");
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
			printf("%d ", A[i][j]);

		printf("\n");
	}
*/
	printf("Length of longest increasing path is %d\n", get_longest_increasing_path(A, M, N, &rinx, &cinx, PathLen));
	print_longest_increasing_path(A, M, N, rinx, cinx, PathLen);
	printf("\n");
}
