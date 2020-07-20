#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

/*
Below are different values returned by fork().

Negative Value: creation of a child process was unsuccessful.
Zero: Returned to the newly created child process.
Positive value: Returned to parent or caller. The value contains process ID of newly created child process.
*/

void multipleForks()
{
	// make two process which run same
	// program after this instruction
	fork();
	fork();
	fork();

	printf("Hello world!\n");
}

int main() {
	multipleForks();
	return 0;
}

