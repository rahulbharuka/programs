#include<stdio.h>
#include<string.h>

#define MAX_LEN 256

typedef struct _test
{
	unsigned int ip;
	unsigned int port;
	unsigned char fqdn[MAX_LEN];
	unsigned char token[MAX_LEN];
} Test;


int main()
{
	Test t1 = {109281263, 8080, "www.test.com", "87aks71d7bas71"};
	printf("Direct initialization: ip=%u port=%u fqdn=%s token=%s\n", t1.ip, t1.port, t1.fqdn, t1.token);
	
	//Test t2 = {t1.ip, t1.port, t1.fqdn, t1.token}; // will throw error for 3rd and 4th parameters.
	Test t2 = {t1.ip, t1.port};
	printf("Indirect initialization: ip=%u port=%u fqdn=%s token=%s\n", t2.ip, t2.port, t2.fqdn, t2.token);
	
	Test t3 = {t1.ip, t1.port};
	strncpy(t3.fqdn, t1.fqdn, MAX_LEN);
	strncpy(t3.token, t1.token, MAX_LEN);
	printf("Indirect initialization: ip=%u port=%u fqdn=%s token=%s\n", t3.ip, t3.port, t3.fqdn, t3.token);
}
