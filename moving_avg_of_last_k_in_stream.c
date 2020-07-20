#include <stdio.h>
#include <stdlib.h>

int main()
{
	int K, curCount = 0, head = 0, var, *lastK;
	float sum = 0, avg = 0;
	printf("Enter the value of k: ");
	scanf("%d", &K);
	lastK = (int *) malloc(sizeof(int) * K);

	printf("Now enter elements in stream; and enter -99 to terminate the stream.\n");
	scanf("%d", &var);
	while(var != -99)
	{
		if (curCount >= K)
		{
			sum = K * avg - lastK[head] + var;
			avg = sum / K;
		}
		else
		{
			//lastK[i] = var;
			sum = curCount * avg + var;
			avg = sum / (curCount+1);
		}

		printf("current average = %f\n", avg);
		lastK[head] = var;
		curCount++;
		head = (head + 1) % K;
		scanf("%d", &var);
	};

	free(lastK);
}
