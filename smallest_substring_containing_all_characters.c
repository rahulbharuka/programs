#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int find_smalllest_substring_containing_all_distinct_characters_of_the_string(char *str)
{
	int len = strlen(str);
	bool ch[26];
	int freq[26], distinct = 0, unique = 0, start = 0, cur_len = 0, min_len = len;

	for (int i = 0; i < 26; i++)
	{
		ch[i] = false;
		freq[i] = 0;
	}

	for (int i = 0; i < len; i++)
		if (!ch[str[i]])
		{
			ch[str[i]] = true;
			distinct++;
		}

	if (distinct == len)
		return min_len;

	for (int i = 0; i < len; i++)
	{
		freq[str[i]]++;

		if (freq[str[i]] == 1)
			unique++;

		if (distinct == unique)
		{
			while (freq[str[start]] > 1)
			{
				freq[str[start]]--;
				start++;
			}

			cur_len = i - start + 1;
			if (cur_len < min_len)
				min_len = cur_len;
		}
	}

	char res[min_len+1];
	strncpy(res, &str[start], min_len);
	printf("corresponding substring is: %s\n", res);
	return min_len;
}

int main()
{
	char str[100000];
	printf("Input string: ");
	scanf("%s", str);
	printf("length of minimum string containing all distinct characters of input string is %d\n",
		find_smalllest_substring_containing_all_distinct_characters_of_the_string(str));
}
