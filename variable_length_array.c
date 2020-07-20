#include<stdio.h>

/*
 * This program compiles successfully because of an optional feature of C
 * called Variable Length Array (VLA).
 */

int main()
{
	int N;
	scanf("%d", &N);
	int arr[N];
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < N; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}
