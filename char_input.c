#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Read input character by character in two different arrays.
int main() {
	int T, N;
	char *sym, *op;
	
	printf("Enter the number of TCs: ");
	scanf("%d", &T);
	
	for (int i = 0; i < T; i++)
	{
		printf("Enter the size of expression: ");
		scanf("%d", &N);
		sym = malloc(sizeof(char) * (N+3)/2);
		op = malloc(sizeof(char) * (N+2)/2);
		getchar();	// required to ignore '\n' after taking input of N

		printf("Enter the expression now: ");
		for (int j = 0, s = 0, p = 0; j < N; j++)
		{
			if (!(j%2))
				//sym[s++] = getchar();
				scanf("%c", &sym[s++]);
			else
		    		//op[p++] = getchar();
				scanf("%c", &op[p++]);
		}

		printf("symbols=%s \tsize=%lu \noperators=%s \tsize=%lu\n", sym, strlen(sym), op, strlen(op));
	}
	return 0;
}
