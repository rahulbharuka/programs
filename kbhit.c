// C++ program to demonstrate use of kbhit()
#include <stdio.h>
#include <ncurses.h>
 
 int main()
{
	while (!kbhit())
		printf("Press a key\n");

	return 0;
}
