#include<stdio.h>
/*
	Substituting the value of i into the macro is impossible, since macro substitutions happen before your code is compiled.
	If you're using GCC, you can see the pre-processor output by adding the '-E' command line argument
	(Note however, that you'll see all the #include's inserted in your code.)

	C is a static language and you can not decide symbol names at runtime.
*/

#define val(a, b) a##b
int main()
{
	int a1 = 10, b1 = 7, i=1;
	printf("%d\n", val(a, 1));	// This is valid 
	printf("%d\n", val(b, i));		// This will throw an error. 
}

