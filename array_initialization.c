#include<stdio.h>

int main()
{
	int a = 10;
	int *p = {&a};
	int *arr[5] = {&a, NULL};
	int i;

	printf("a=%d\n", a);
	printf("p=%p\t*p=%d\n", p, *p);
	for (i=0; i<5; i++)
		if (arr[i])
			printf("arr[%d]=%p\t*arr[%d]=%d\n", i, arr[i], i, *arr[i]);

	return 0;
}
