#include<stdio.h>

/*
 * printf is expecting a valid (i.e. non-NULL) pointer for its %s argument so passing it a NULL is officially undefined.
 * It may print "(null)" or it may delete all files on your hard drive--either is correct behavior as far as ANSI is concerned.
 */

int main()
{
	printf("Test %s\n", NULL); // gcc calls printf() which has special case for handling NULL argument.
	printf("%s\n", NULL);	// gcc optimizes this call to puts() which does not handle NULL argument.
}
