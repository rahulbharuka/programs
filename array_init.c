#include <stdio.h>

int main()
{
	int count;
	int arr[10];

	scanf("%d", &count);

	for (int i = 0; i < count; i++)
		scanf("%d", &arr[i]);

	printf("\n");
	for (int i = 0; i < count; i++)
		printf("%d ", arr[i]);

	return 0;
}
