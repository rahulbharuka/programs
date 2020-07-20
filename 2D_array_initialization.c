#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N, M;
	char **grid;
	scanf("%d", &N);
	scanf("%d", &M);
	grid = (char **) malloc(sizeof(char *) * N);
	getchar();
	for (int j = 0; j < N; j++)
	{
		grid[j] = (char *) malloc(sizeof(char) * M + 1);
		fgets(grid[j], M+1, stdin);
		getchar();
		//grid[j][2] = 'A';
		printf("%s\n", grid[j]);
	}

	return 0;
}
