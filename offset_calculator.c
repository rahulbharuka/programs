#include<stdio.h>

#define offsetof(type,field) (size_t)(&(((type *)0)->field))

typedef struct tmp
{
	int a;
	char b;
	float c;
} tmp_t;

int main()
{
	tmp_t t = {10, 'B', 99.99};
	printf("%lu\n", offsetof(tmp_t, c));
}
