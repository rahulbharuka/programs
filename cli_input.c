/* What's wrong with this program? */
#include <stdio.h>

//int main(int argc, char const * argv)	//Incorrect
int main(int argc, char const ** argv)
{
	for( int i = 0; i < argc; ++i)
	{
		printf("%p %s\n", argv[i], argv[i]);
	}
} 
