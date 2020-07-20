#include <stdio.h>

/* Describe the code below */

struct s {
	double f;
	int i;
	char c[3];
	void *p;
	int x[0];
};

int main( int argc, char ** argv ) {

	struct s temp;

	printf("The size of the struct is %lu \n", sizeof(temp));

	printf("The size of the double is %lu \n", sizeof(temp.f));

	printf("The size of a character array is %lu \n", sizeof(temp.c));

	printf("The size of a void pointer is %lu \n", sizeof(temp.p));

	printf("The size of a integer array is %lu \n", sizeof(temp.x));

	printf("The size of a integer is %lu \n", sizeof(temp.i));

	return 0;

} 
