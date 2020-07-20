#include<stdio.h>
#include<string.h>

/*
If you want to get size of memory buffer, that contains your string, and you have pointer to it:
	1. If it is dynamic array(created with malloc), it is impossible to get it size, since compiler doesn't know what pointer is pointing at. 
        2. If it is static array, you can use sizeof to get its size.
*/

int main()
{
	char *str = "rahul";
	printf("%s:\t", str);
	printf("%lu\t", sizeof(str));	// returns size of pointer.
	printf("%lu\t", sizeof(*str));	// returns size of first element of str.
	printf("%lu\n", strlen(str));	// returns size of *str.

	char arr[] = "pranita";
	printf("%s:\t", arr);
	printf("%lu\t", sizeof(arr));	// returns size of arr including terminating null character.
	printf("%lu\t", sizeof(*arr));	// returns size of first element of arr.
	printf("%lu\n", strlen(arr));	// returns size of arr.
}
