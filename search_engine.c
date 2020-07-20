#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_LINES 1000
#define MAX_LINE_SIZE 1001

void search_engine(char **input, int n, char **output)
{
	int j, c = -1;
	char *ch, *s;
	for(int i = 0; i < n; i++)
	{
		//printf("%s\n", input[i]);
		s = input[i];
		j = 0;
		if ((ch = strchr(s, '\\')) && ((*(ch+1) == 'b') || (*(ch+1) == 'n')))
		{
			if (*(ch+1) == 'n')
			{
				c++;
				output[c] = (char *)malloc(sizeof(char) * MAX_LINE_SIZE);
				strncpy(output[i], input[i], ch - s);
				printf("%s\n", output[i]);
				s = ch + 2;
			}
				
			printf("%lu\n", ch - input[i]);
		}
		else
		{
			c++;
			output[c] = (char *)malloc(sizeof(char) * MAX_LINE_SIZE);
			strncpy(output[i], input[i], strlen(input[i]));
			printf("%s\n", output[i]);
		}
		//printf("ch=%c\n", *ch);
	}
}

int main()
{
	int c = -1;
	char **input, **output, *ch;
	input = (char **) malloc(sizeof(char *) * MAX_LINES);
	output = (char **) malloc(sizeof(char *) * MAX_LINES);
	do
	{
		c++;
		input[c] = (char *) malloc(sizeof(char) * MAX_LINE_SIZE);
		fgets(input[c], MAX_LINE_SIZE, stdin);
		if ((ch = strchr(input[c], '\n')))
			*ch = '\0';
		
		if (!strcmp(input[c], "$"))
			break;
		//printf(">%s<\n", input[i]);
	} while (1);

	search_engine(input, c, output);
}
