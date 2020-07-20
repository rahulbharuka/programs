#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

bool isQueenColSafe(int **board, int N, int col)
{
	int row;
	for (row = 0; row < N; row++)
	{	if (board[row][col])
		return false;
	}

	return true;
}

bool isQueenRowSafe(int **board, int N, int row)
{
	int col;
	for (col = 0; col < N; col++)
		if (board[row][col])
			return false;

	return true;
}

bool isQueenDiagonalSafe(int **board, int N, int r, int c)
{
	int row, col;
	for (row = r, col = c; (row < N) && (col < N); row++, col++)
		if (board[row][col])
			return false;

	for (row = r, col = c; (row >= 0) && (col >= 0); row--, col--)
		if (board[row][col])
			return false;

	for (row = r, col = c; (row >= 0) && (col < N); row--, col++)
		if (board[row][col])
			return false;

	for (row = r, col = c; (row < N) && (col >= 0); row++, col--)
		if (board[row][col])
			return false;

	return true;
}


bool isQueenSafe(int **board, int N, int row, int col)
{
	return isQueenRowSafe(board, N, row)
		&& isQueenColSafe(board, N , col)
		&& isQueenDiagonalSafe(board, N, row, col);

}

bool solveNQueen(int **board, int N, int col, int Q)
{
	static bool status = false;
	int r, c, row;

	if (!col)
		status = false;

	for(row = 0; row < N; row++)
	{
		//printf("col=%d row=%d\n", col, row);
		if (isQueenSafe(board, N, row, col))
		{
			board[row][col] = 1;
			Q++;

			if (Q == N)
			{
				printf("[");
				for (c = 0; c < N; c++)
					for(r = 0; r < N; r++)
						if (board[r][c])
							printf("%d ", r+1);

				printf("] ");
				status = true;
			}

			solveNQueen(board, N, col+1, Q);
			board[row][col] = 0;
			Q--;
		}

	}

	return status;
}


int main() {
	int i, j, T, N;
	scanf("%d", &T);

	for (i = 0; i < T; i++)
	{
		scanf("%d", &N);
		int **board = (int **) calloc(N, sizeof(int*));
		for (j = 0; j < N; j++)
			board[j] = (int *) calloc(N, sizeof(int));

		if (!solveNQueen(board, N, 0, 0))
			printf("-1\n");
		else
			printf("\n");

		for (j = 0; j < N; j++)
			free(board[j]);

		free(board);
	}

	return 0;
}
