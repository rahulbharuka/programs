#include<stdio.h>

int main()
{
	unsigned int val = 0xffffffff;
	unsigned int rval = ((unsigned long long)val+7)/8;
	printf("val = %x\t rval = %d\n", val, rval);

	return 0;
}
