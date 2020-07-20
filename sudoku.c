#include <stdio.h>
#include <stdbool.h>

bool findUnassigned(int grid[9][9], int *row, int *col)
{
	int r, c;
	for (r = 0; r < 9; r++)
		for (c = 0; c < 9; c++)
			if (grid[r][c] == 0)
			{
				*row = r;
				*col = c;
				return true;
			}

	return false;
}

bool isColumnSafe(int grid[9][9], int row, int num)
{
	for (int col = 0; col < 9; col++)
		if (grid[row][col] == num)
			return false;

	return true;
}

bool isRowSafe(int grid[9][9], int col, int num)
{
	for (int row = 0; row < 9; row++)
		if (grid[row][col] == num)
			return false;

	return true;
}

bool isBoxSafe(int grid[9][9], int sRow, int sCol, int num)
{
	for (int r = 0; r < 3; r++)
		for (int c = 0; c < 3; c++)
			if (grid[sRow + r][sCol + c] == num)
				return false;

	return true;
}

bool isNumSafe(int grid[9][9], int row, int col, int num)
{
	if (isColumnSafe(grid, row, num) && isRowSafe(grid, col, num)
			&& isBoxSafe(grid, row - (row % 3), col - (col % 3), num))
		return true;

	return false;
}

bool solveSudoku(int grid[9][9])
{
	int row, col;

	if (!findUnassigned(grid, &row, &col))
		return true;

	for (int num = 1; num <= 9; num++)
	{
		if (isNumSafe(grid, row, col, num))
		{
			grid[row][col] = num;

			if (solveSudoku(grid) == true)
				return true;

			grid[row][col] = 0;
		}
	}
	return false;
}

int main()
{
	int T, grid[9][9], i, row, col;
	scanf("%d", &T);

	for (i = 0; i < T; i++)
	{
		for (row = 0; row < 9; row++)
			for (col = 0; col < 9; col++)
				scanf("%d", &grid[row][col]);

		if (solveSudoku(grid) == true)
		{
			for (row = 0; row < 9; row++)
				for (col = 0; col < 9; col++)
					printf("%2d", grid[row][col]);

			printf("\n");
		}
		else
			printf("No solution exists\n");
	}

	return 0;
}
