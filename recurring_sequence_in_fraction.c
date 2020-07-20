#include<stdio.h>


void findRecurringSequenceInFraction(int numr, int denr)
{
	char res[100];
	int hash[100] = {[0 ... 99] = -1};
	int rem, t_res;
	int inx = 0, i = 0;
	rem = numr % denr;

	while ((rem != 0) && (hash[rem] == -1))
	{
		hash[rem] = i++;
		rem *= 10;
		t_res = rem / denr;
		res[inx++] = '0' + t_res;
		rem = rem % denr;
	}

	res[inx] = '\0';
	(rem == 0) ? printf("No recurring sequence\n") :
		printf("Recurring sequence in fraction is %s\n", &res[hash[rem]]);


}

int main()
{
	int numr, denr;
	scanf("%d %d", &numr, &denr);
	findRecurringSequenceInFraction(numr, denr);
}
