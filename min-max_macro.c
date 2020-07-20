#include <stdio.h>

/*
__typeof__() and __typeof() are compiler-specific extensions to the C language, because standard C does not include such an operator. Standard C requires compilers to prefix language extensions with a double-underscore (which is also why you should never do so for your own functions, variables, etc.)

typeof() is exactly the same, but throws the underscores out the window with the understanding that every modern compiler supports it. (Actually, now that I think about it, Visual C++ might not. It does support decltype() though, which generally provides the same behaviour as typeof().)

All three mean the same thing, but none are standard C so a conforming compiler may choose to make any mean something different.
*/

/*
Here is how the two together can be used to define a safe “maximum” macro which operates on any arithmetic type and evaluates each of its argument exactly once: 
*/

#define min_a(a,b) (((a)<(b)) ? (a) : (b))

#define min_b(a,b) \
({ __typeof__ (a) _a = (a); \
 __typeof__ (b) _b = (b); \
 _a < _b ? _a : _b; \
 })

int minimum(int a, int b)
{
	return (a<b?a:b);
}

int main(void)
{
	int u = 5, v = 10;
	int p = 5, q = 10;

	int w = min_a(u++, v++); // has double expansion issue.
	printf ("w %d, u %d (were expecting 6), v %d\n", w, u, v);

	int r = min_b(p++, q++); //right version
	printf ("r %d, p %d (were expecting 6), q %d\n", r, p, q);

	int i = 5, j = 10;
	int k = minimum(++i, ++j);
	printf ("i %d, j %d, k %d\n", i, j, k);

	return 0;
}
