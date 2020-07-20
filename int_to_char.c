#include<stdio.h>

int main()
{
	int arr[5];

	for(int i = 0; i < 5; i++)
		scanf("%c", &arr[i]);

	printf("Entered content: ");
	for(int i = 0; i < 5; i++)
		printf("%0x(%c) ", arr[i], arr[i]);

	printf("\n");
}
