#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	//char *str;
	int N;
	scanf("%d", &N);
	//str = malloc(sizeof(char) * N + 1);
	char format[6], name[10];
	sprintf(format, "%%%ds", N);
	scanf(format, name);
	//fflush(stdin);
	//fgets(name, sizeof(name), stdin);
	//printf("\n%s", str);
	printf("\n%s\n", name);
	return 0;
}
