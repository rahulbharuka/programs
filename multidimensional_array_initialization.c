#include<stdio.h>

/*
In C/C++, initialization of a multidimensional arrays can have left most dimension as optional. Except the left most dimension, all other dimensions must be specified.
*/

int main()
{
//  int a[][][2] = { {{1, 2}, {3, 4}}, { {5, 6}, {7, 8} } };  // error

  int b[][2][2] = { {{1, 2}, {3, 4}}, { {5, 6}, {7, 8} } };  // works!

  printf("%lu", sizeof(b)); 
  getchar();
  return 0;
}
