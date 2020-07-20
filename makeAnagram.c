#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

/* 
Input Format

The first line contains a single string, a.
The second line contains a single string, b.

Constraints

    It is guaranteed that and consist of lowercase English alphabetic letters (i.e., through ).

    Output Format

    Print a single integer denoting the number of characters you must delete to make the two strings anagrams of each other.

Example:
1.
 Input:
	cde
	abc
 Output:
 	4

2.
 Input:
	fcrxzwscanmligyxyvym
	jxwtrhvujlmrpdoqbisbwhmgpmeoke
 Output:
 	30
*/

int makeAnagram(char *a, char *b) {
	char alpha[26] = {0};

	int a_len = strlen(a), b_len = strlen(b);
	for (int i = 0; i < a_len; i++)
		alpha[a[i]-'a']++;

	for (int j = 0; j < b_len; j++)
		alpha[b[j]-'a']--;

	int delCount = 0;
	for (int k = 0; k < 26; k++)
		if (alpha[k])
			delCount += abs(alpha[k]);

	return delCount;
}

int main(){
	char* a = (char *)malloc(512000 * sizeof(char));
	scanf("%s",a);
	char* b = (char *)malloc(512000 * sizeof(char));
	scanf("%s",b);
	printf("%d", makeAnagram(a, b));

	return 0;
}

