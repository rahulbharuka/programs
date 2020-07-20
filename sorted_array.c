#include <stdio.h>
#include <math.h>

int main()
{
	int i, small_index, large_index, size = 0;
	int arr[10];
	printf("\nEnter number of elements: ");
	scanf("%d", &size);

	for (i=0; i<size; i++)
		scanf("%d", &arr[i]);
		
	small_index = large_index = 0;

	for (i=1; i<size; i++)
	{
		//printf("%d ", arr[i]);
		if (arr[i] < arr[small_index])
			small_index = i;

		if (arr[i] > arr[large_index])
			large_index = i;
	}

	printf("Smallest element=%d, largest element=%d\n", arr[small_index], arr[large_index]);

	if (abs(small_index-large_index) == 1)
	{
		if (small_index < large_index)
			printf("The input arrray is descending.\n");
		else
			printf("The input arrray is ascending.\n");
	}
	else
	{
		if (small_index < large_index)
			printf("The input arrray is ascending.\n");
		else
			printf("The input arrray is descending.\n");
	}

	return 0;
}
