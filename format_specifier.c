#include<stdio.h>

/*
* Refer: http://www.cplusplus.com/reference/cstdio/scanf/
*
* A format specifier for scanf follows this prototype:
*	%[*][width][length]specifier
*/

int main()
{
	char str[]="4211";
	unsigned char m;
	
	// Read next two symobols(width=2) in hex format(specifier=0x) and store them in argument of type unsigned char* (length=hh). 
	sscanf(str, "%02hhx", &m);
	printf("%d\n", m); // print output in decimal format.
	printf("%x\n", m); // print output in hex format.

	char str2[] = "4e_1e_6f_73_11_2a,2a_ad_6f_7e_74_47,ea_1c_7e_1a_2d_b4,a2_26_30_f2_a0_88,9a_6d_3a_8e_8e_f5";
	unsigned char ent[6];

	sscanf(str2, "%02hhx_%02hhx_%02hhx_%02hhx_%02hhx_%02hhx",
		&ent[0], &ent[1], &ent[2], &ent[3], &ent[4], &ent[5]);

	printf("%x:%x:%x:%x:%x:%x\t%x\n", ent[0], ent[1], ent[2], ent[3], ent[4], ent[5], *ent);

}
