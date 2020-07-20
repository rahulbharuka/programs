#include <stdio.h>

int main()
{
	int a = 2147483647, b = 2;
	int c = a * b;
	long long d = a * b;
	long long e = (long long) a * b;

	printf("\ncase [int a, b; a * b;]:\t %d * %d = %d\n\n", a, b, a * b);

	printf("case [int a, b; int c = a * b;]:\t %d * %d = %d\n\n", a, b, c);
	
	printf("case [int a, b; long long d = a * b;]:\t %d * %d = %lld\n\n", a, b, d);
	
	printf("case [int a, b; long long e = (long long) a * b;]:\t %d * %d = %lld\n\n", a, b, e);
	
	printf("case [int a, b; (long long) a * b;]:\t %d * %d = %lld\n\n", a, b, (long long) a * b);
}
