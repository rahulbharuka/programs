#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* longestPalindrome(char* s, char* new_str)
{
	//printf("\n%s", s);
	int i, j, k, len, new_len, start_index = 0;

	int max_len = 1;

	while (s[i++] != '\0')
		len++;

	if (len <= 1)
		return s;

	for (i = 0; i < len;)
	{
		j = k = i;

		while ((k < (len-1)) && s[k] == s[k+1])
			k++;

		i = k + 1;

		while ((k < (len-1)) && (j > 0) && (s[j-1] == s[k+1]))
		{
			j--;
			k++;
		};

		new_len = k - j  + 1;

		if (new_len > max_len)
		{
			max_len = new_len;
			start_index = j;
		}
	}

	//printf("\nmax_len=%d start_index=%d", max_len, start_index);

	strncpy(new_str, &s[start_index], max_len);

	return new_str;
}

int main()
{
	char str[] = "cabad";

	char *new_str =  malloc(4);
	//printf("str=%s", str);
	longestPalindrome(str, new_str);
	printf("Longest Palindrome string: %s\n", new_str);
	return 0;

}
