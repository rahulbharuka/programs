#include<stdio.h>

// minimum moves required to solve this problem is (2^n - 1).

void solveTowerOfHanoi(int n, char from_peg, char to_peg, char aux_peg)
{
	if (n == 1)
	{
		printf("Move the top disk from peg %c to peg %c\n", from_peg, to_peg);
		return;
	}

	solveTowerOfHanoi(n-1, from_peg, aux_peg, to_peg);
	printf("Move the top disk from peg %c to peg %c\n", from_peg, to_peg);
	solveTowerOfHanoi(n-1, aux_peg, to_peg, from_peg);
}

int main()
{
	int n = 4;
	solveTowerOfHanoi(n, 'A', 'B', 'C');
}
