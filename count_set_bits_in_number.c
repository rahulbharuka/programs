#include <stdio.h>

int main()
{
	int num;
	scanf("%d", &num);
	printf("Number of 1s in %d is %d\n", num,  __builtin_popcount(num));
}
