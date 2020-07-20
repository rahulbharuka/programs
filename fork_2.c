#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

/*
Below are different values returned by fork().

Negative Value: creation of a child process was unsuccessful.
Zero: Returned to the newly created child process.
Positive value: Returned to parent or caller. The value contains process ID of newly created child process.
*/


void forkexample() 
{
    // child process because return value zero
	if (fork()==0)
		printf("Hello from Child!\n");

	// parent process because return value non-zero.
	else    
		printf("Hello from Parent!\n"); 
}

int main() {
	forkexample();
	return 0;
}

