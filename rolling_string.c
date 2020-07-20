#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char *ch, s[151];
	int k;
	scanf("%d", &k);
	getchar();
	char **operation = (char **) malloc(sizeof(char *) * k);
	for (int i = 0; i < k; i++)
	{
		operation[i] = (char*) malloc(sizeof(char) * 10);
		fgets(operation[i], 11, stdin);
		if ((ch = strchr(operation[i], '\n')))
			*ch = '\0';

		//printf(">%s<\n", operation[i]);
	}
	//rolling_jobs(
}
