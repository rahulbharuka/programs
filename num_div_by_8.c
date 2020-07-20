#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

void swap(char* a, char* b)
{
	char temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int permute(int lo, int hi, char* str)
{
	char temp;
	int num, res;
	printf("%s %d %d\n", str, lo, hi);
	if (lo == hi) {
		num = atoi(str);
	//	printf("%d\n", num);
		return ((num%8));
	}	
	else {
		swap(&str[lo], &str[lo+1]);
		res = permute(lo+1, hi, str);
		swap(&str[lo+1], &str[lo]);
		return res;
	}
}

/*
 * Complete the function below.
 */
void ispermuation_divisibleby8(int arr_size, char** arr) {
	int idx, i, lo, hi, sz, res;
	char temp;

	for (idx=0; idx < arr_size; idx++)
	{
		sz = 0;
//		printf("%s\n", arr[idx]);
		sz = strlen(arr[idx]);
//		printf("sz=%d\n", sz);
		lo = res = 0;
		hi = sz-1;
		
		for (i=lo; i<=hi; i++)
		{
			res = permute(lo, hi, arr[idx]);

			if (!res)
			{
				printf("YES %d\n", idx);
				break;
			}
		}

		if (i == (hi+1))
			printf("NO %d\n", idx);
	}
}

int main() {

	int _arr_size = 0;
	int _arr_i;
	scanf("%d\n", &_arr_size);
	char* _arr[_arr_size];
	for(_arr_i = 0; _arr_i < _arr_size; _arr_i++) {
		char* _arr_item;
		_arr_item = (char *)malloc(10240 * sizeof(char));
		scanf("\n%[^\n]",_arr_item);
		_arr[_arr_i] = _arr_item;
	}

	ispermuation_divisibleby8(_arr_size, _arr);

	return 0;
}
