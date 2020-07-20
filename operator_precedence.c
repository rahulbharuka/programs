#include<stdio.h>

int main()
{
	printf("Result: %d\n", 3*5<12);
	if (1*12<11)
		printf("* has higher precedence over <\n");
	else
		printf("< has higher precedence over *\n");
}
