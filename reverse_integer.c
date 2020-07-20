#include <stdio.h>

int reverse(int x) {
	int rem;
	long int rev;

	do
	{
		rem = x % 10;
		rev  = rev * 10 + rem;
		x = x/10;
	}while (x);

	if ((rev <= -2147483648) || (rev >= 2147483647))
		return 0;
	else
		return rev;
}


int main()
{
	int res = reverse(1534236469);
	printf("\nnum=%d\n", 1534236469);
	printf("\nres=%d\n", res);
	return 0;
}
