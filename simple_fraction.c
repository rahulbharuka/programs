#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int T, N, D, quot, rem, i, j; //TC count, numerator, denominator, quotient, remainder, decimal
	scanf("%d", &T);
	for (i = 0; i < T; i++)
	{
		scanf("%d", &N);
		scanf("%d", &D);

		quot = N / D;
		rem = N % D;
		int fract[100], remainder[100], inx = 0, pos = -1, p;
		if (!rem)
			printf("%d\n", quot);
		else
		{
			printf("%d.", quot);

			do
			{
				rem *= 10;
				quot = rem / D;

				for (p = 0; (p < inx) && (remainder[p] != rem); p++);

				if (p < inx)
				{
					pos = p;
					break;
				}

				remainder[inx] = rem;
				fract[inx] = quot;
				inx++;
				rem = rem % D;

			} while (rem);
		
			if (pos == -1)
			{
				for (j = 0; j < inx; j++)
					printf("%d", fract[j]);
			}
			else
			{
				for (j = 0; j < pos; j++)
					printf("%d", fract[j]);

				printf("(");

				for (; j < inx; j++)
					printf("%d", fract[j]);

				printf(")");
			}
			printf("\n");
		}
	}
	return 0;
}
