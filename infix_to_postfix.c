#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include "stack.h"

bool isOperand(char ch)
{
	return ( ((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z')) );
}

bool isOperator(char ch)
{
	switch(ch)
	{
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
			return true;
		default:
			return false;
	}
}

int precedence(char op)
{
	switch(op)
	{
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
		default:
			return -1;
	}
}

bool infix_to_postfix(char *exp, unsigned int len)
{
	Stack *s = createStack(len);
	bool ret = false;
	int inx = 0;

	for(int i = 0; i < len; i++)
	{
		if (isOperand(exp[i]))
			exp[inx++] = exp[i];
		else if (exp[i] == '(')
			push(s, exp[i]);
		else if (exp[i] == ')')
		{
			while (!isEmpty(s) && peek(s) != '(')
				exp[inx++] = pop(s);

			if (isEmpty(s) || peek(s) != '(')
			{
				printf("\nInvalid input expression: missing (\n");
				goto error;
			}
			else
				pop(s);	// Discard '('
		}
		else if (isOperator(exp[i]) && (precedence(exp[i]) != -1))
		{
			while (!isEmpty(s) && precedence(peek(s)) >= precedence(exp[i]))
				exp[inx++] = pop(s);

			push(s, exp[i]);
		}
		else
		{
			printf("\nInvalid character: %c\n", exp[i]);
			goto error;
		}
	}

	while (!isEmpty(s))
		exp[inx++] = pop(s);

	exp[inx] = '\0';
	ret = true;
error:
	freeStack(s);
	return ret;
}

int main()
{
	int len;
	printf("Enter the length of infix expression: ");
	scanf("%d", &len);
	getchar();	// to skip \n after len.
	len++;
	char *exp = (char *) malloc(sizeof(char) * len);
	printf("Now enter the infix expression: ");
	fgets(exp, len, stdin);
	printf("The entered expression is: [%s]\n", exp);
	
	// Remove '\n' if string was shorter than specified length.
	char *p = strchr(exp, '\n');
	if (p)
		*p = '\0';
	
	//printf("Now the corrected expression is: [%s]\n", exp);
	//printf("Size of the input expression is: %lu\n", strlen(exp));
	if (infix_to_postfix(exp, strlen(exp)))
		printf("The corresponding postfix expression is: %s\n", exp);
}
