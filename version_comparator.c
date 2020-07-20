#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

int version_compare(char *v1, char *v2)
{
	char *c1, *c2;
	int n1, n2;

	while ((c1 = strtok_r(v1, ".", &v1)) && (c2 = strtok_r(v2, ".", &v2)))
	{
		n1 = atoi(c1); 
		n2 = atoi(c2);

		if (n1 != n2)
			return n1 > n2 ? 1 : -1;
	}

	return 0;
}

int main()
{
	int res;
	
	char v1[] = "1.10";
	char v2[] = "1.1";
	/* NOTE: strings must be printed before invoking strtok()/strtok_r() because
		both these functions modifies the passed string and split it into tokens terminated by \0.
	*/
	printf("%s\t%s\t",v1, v2);
	res = version_compare(v1, v2);
	assert(res == 1);
	printf("\tres = %d\n", res);
	
	char v3[] = "1.0";
	char v4[] = "1.1";
	printf("%s\t%s\t",v3, v4);
	res = version_compare(v3, v4);
	assert(res == -1);
	printf("\tres = %d\n", res);
	
	char v5[] = "1.2.1";
	char v6[] = "1.2.1";
	printf("%s\t%s\t",v5, v6);
	res = version_compare(v5, v6);
	assert(res == 0);
	printf("\tres = %d\n", res);
	
	return 0;
}
