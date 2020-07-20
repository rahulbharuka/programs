#include<stdio.h>

// ##	token pasting or token concatenation operator
// #	stringizing operator

#define P(A) printf(#A"=%d\n",A)	// #A translates to "A" i.e. string literal. That's why no need of " in printf.
#define	C(A) #A
#define D(A, B) printf(C(A) C(B) "\n")

int main()
{
	int x=2,y=3;
	P(x);
	P(y);
	printf("%s%s\n", C(x), C(y));
	D(x, y);
}
