#include<stdio.h>
#include<string.h>

#define ns_ppeid 0

int main()
{
	char str[100];
	char *s = "Hi there! ";

	//sprintf(str, "%s", "Hello World! ");
	snprintf(str, strlen(s)+1, "%s", s);
	printf("%s%lu\n", str, strlen(s));
	sprintf(str+strlen("Hello World! "), "Its Rahul.");
	//sprintf(str+strlen("Hello World! "), NULL);
	printf("%s\n", str);


	char trap_entity_name[128];
	sprintf(trap_entity_name, "%d", ns_ppeid);
	printf("%s\n", trap_entity_name);
}
