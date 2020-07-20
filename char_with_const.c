#include<stdio.h>

/*

const always modifies the thing that comes before it (to the left of it), EXCEPT when it's the first thing in a type declaration, where it modifies the thing that comes after it (to the right of it).

So, "char const *" is same as "const char *"


int       *      	mutable_pointer_to_mutable_int;
int const *      	mutable_pointer_to_constant_int;
int       *const 	constant_pointer_to_mutable_int;
int const *const 	constant_pointer_to_constant_int;

*/

int main()
{
	const char *str = "rahul";	// same as "char const *". str is pointer to a constant c-string.
	char tmp[] = "bharuka";
	
	str = tmp; // Valid. The pointer can be changed.
//	str[0] = "P"; // Invalid. Because the string is in ready-only data segment and its constant. 

	printf("str = %p *str = %s\n", str, str);



	char *const s = "pranita";	// s is a constant pointer to a c-string.
	//s = tmp; // Invalid. Because pointer is constant.
	
	printf("s = %p *str = %s\n", s, s);

	

	const char *const ss = "parah"; // ss is a constant pointer to a constant c-string.
	ss = tmp; // Invalid. Because pointer is constant.
	
	printf("ss = %p *str = %s\n", ss, ss);

}
