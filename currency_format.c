#include<stdio.h>
#include<string.h>

int main()
{
	char str[100], res[100], *ch;
	fgets(str, sizeof(str), stdin);
	if ((ch = strchr(str, '\n')))
		*ch = '\0';
	printf("len=%lu >%s<\n", strlen(str), str);
	ch = strtok(str, ".");
	while (ch)
	{
		printf("\t%s %p\n", ch, ch);
		ch = strtok(NULL, ".");
	};
	printf("arr=%s %p\n", str, str);
}
