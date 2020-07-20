#include<stdio.h>

/*
// Count the number of 1's in binary representation of a number.
int main()
{
	unsigned int num, c = 0;
	scanf("%d", &num);
		
	while(num)
	{
		if (num & 1)
			c++;

		num >>= 1;
	}

	printf("res = %d\n", c);
}
*/

// Count the number of 1's in binary representation of a number.
int main()
{
	unsigned int num, c = 0;
	static int arr[] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4};
	scanf("%d", &num);
		
	while(num)
	{
		c += arr[num & 15];

		num >>= 4;
	}

	printf("res = %d\n", c);
}
