#include<stdio.h>

int min(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	int m = 2;
	printf("%d\n", m > min(5, 7));
}
