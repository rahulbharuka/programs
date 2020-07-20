#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int T, N;
	char format[6], *str;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
	    scanf("%d", &N);
	    str = malloc(sizeof(char) * (N+1));
	    sprintf(format, "%%%ds", N);
	    scanf(format, str);
	    printf("string=%s size=%lu\n", str, strlen(str));
	}
	return 0;
}
