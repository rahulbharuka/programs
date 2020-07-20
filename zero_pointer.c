#include<stdio.h>

int main()
{
	char *c;
	c = 0;

	if (c == NULL)
		printf("NULL pointer\n");
	else
		printf("Not a NULL pointer\n");

	return 0;
}
