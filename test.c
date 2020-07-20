#include<stdio.h>
#include<math.h>


void func();

void func()
{

	static int idx = 0;

	idx = 0;
	for (; idx < 0x100000000; ++idx);

	printf("%d  ", idx);
}


int main()
{
//	func();

	printf("res = %d, val=%lf\n", (2 <= ((10 * (1-0.8)))), (10 * (1-0.8)));

//	func();
	return 0;
}
