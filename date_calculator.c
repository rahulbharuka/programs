#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isLeapYear(int year)
{
	if (year%4)
		return false;
	else if (year%100)
		return true;
	else if (year%400)
		return false;
	else
		return true;
}

void substractDays(int date, int month, int year, int diff)
{
	int rem = date;

	if (diff > rem)
	{
		diff -= rem;
		date = 0;
		month--;

		if (!month)
		{
			month = 12;
			year--;
		}

		while (diff)
		{
			if ((month == 2) && isLeapYear(year) && (diff <= 29))
				break;

			if (diff <= days[month])
				break;

			diff -= days[month];
			if ((month == 2) && isLeapYear(year))
				diff--;

			month--;

			if (!month)
			{
				month = 12;
				year--;
			}
		}

		date = days[month] - diff;
	}
	else
		date -= diff;

	printf("The desired date is %d/%d/%d\n", date, month, year);
}

void addDays(int date, int month, int year, int diff)
{
	int rem = days[month] - date;

	if ((month == 2) && isLeapYear(year))
		rem++;

	if (diff > rem)
	{
		diff -= rem;
		date = 0;
		month++;

		if (month == 13)
		{
			month = 0;
			year++;
		}

		while (diff)
		{
			if ((month == 2) && isLeapYear(year) && (diff <= 29))
				break;

			if (diff <= days[month])
				break;

			diff -= days[month];
			if ((month == 2) && isLeapYear(year))
				diff--;

			month++;
			
			if (month == 13)
			{
				month = 0;
				year++;
			}
		}
	}
	
	date += diff;

	printf("The desired date is %d/%d/%d\n", date, month, year);
}

int main()
{
	char str[11], *ch;
	static int date, month, year, diff;
	fgets(str, sizeof(str), stdin);

	
	ch = strtok(str, "-/");
	if (ch)
		date = atoi(ch);

	ch = strtok(NULL, "-/");
	if (ch)
		month = atoi(ch);

	ch = strtok(NULL, "-/");
	if (ch)
		year = atoi(ch);

	if ((year < 0) || (month < 1) || (month > 12) || (date > 31) ||
		((date > days[month]) && !((month == 2) && isLeapYear(year) && (date <= 29))))
	{
		printf("Invalid date\n");
		exit(0);
	}

	scanf("%d", &diff);
	printf("Entered date is %d/%d/%d\n", date, month, year);
	
	if (diff >= 0)
		addDays(date, month, year, diff);
	else
		substractDays(date, month, year, -1 * diff);

	return 0;
}
