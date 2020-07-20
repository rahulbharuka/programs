#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int l1, l2;
	scanf("%d %d", &l1, &l2);
	if (l1 == l2)
	{
		char *s1 = (char *) malloc(sizeof(char) * (l1 * 2 + 1));
		char *s2 = (char *) malloc(sizeof(char) * (l2+1));
		getchar();
		fgets(s1, l1+1, stdin);
		getchar();
		fgets(s2, l2+1, stdin);
		//printf("S1: >%s<\n", s1);
		//printf("S2: >%s<\n", s2);
		strcat(s1, s1);
		//printf("S1S1: >%s<\n", s1);
		if (strstr(s1, s2))
		{
			printf("The two strings are rotation of each other.\n");
			return 0;
		}
	}
	
	printf("Strings are NOT rotation of each other.\n");
}
