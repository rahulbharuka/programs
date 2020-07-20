#include <stdio.h>

/*
*	Any of these will result in Segmentation Fault:
*		A segmentation fault occurs when a program attempts to access a memory location that it is not allowed to access,
*		or attempts to access a memory location in a way that is not allowed (for example, attempting to write to a
**		read-only location, or to overwrite part of the operating system).
*/

int main()
{

	int num;
	printf("Enter case number to execute [1-4] :");
	scanf("%d", &num);
	int *p = NULL;
	int a, b, c; // some integers
	int *pi;     // a pointer to an integer
	char *str = "Foo"; // Compiler marks the constant string as read-only
	char tmp[] = "Bar";

	switch(num)
	{

		//	int z = 212/0;
		case 1:

			printf("Before-1\n");
			*p = 1;
			printf("After-1\n");
			break;
		case 2:

			a = 5;
			pi = &a; // pi points to a
			b = *pi; // b is now 5
			pi = NULL;

			printf("Before-2\n");
			c = *pi; // this is a NULL pointer dereference
			printf("After-2\n");
			break;
		case 3:
			printf("Before-3\n");
			*str = 'b'; // Which means this is illegal and results in a segfault
			printf("After-3\n");
			break;

		case 4:
			printf("Before-4\n");
			tmp[1]='e';
			printf("%s, size=%lu\n", tmp, sizeof(tmp));
			printf("After-4\n");
			break;

		default:
			printf("Invalid input !\n");
	}
	return 0;
}
