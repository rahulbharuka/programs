#include <iostream>
#include <string>
using namespace std;

class Solution {
	public:
		long myAtoi(string str) {
			int len = str.length(), sign = 1, i = 0;
			long sum = 0;

			if (len <= 0)
				return 0;

			while ((i < len) && (str[i] == ' '))
				i++;

			if (i == len)
				return 0;

			if (str[i] == '-')
			{
				sign = -1;
				i++;
			}
			else if (str[i] == '+')
				i++;
			else if ((str[i] < '0') || (str[i] > '9'))
				return 0;

			for (; i < len; i++)
			{
				switch (str[i])
				{
					case '0':
						sum = sum * 10;
						break;
					case '1':
						sum = sum * 10 + 1;
						break;
					case '2':
						sum = sum * 10 + 2;
						break;
					case '3':
						sum = sum * 10 + 3;
						break;
					case '4':
						sum = sum * 10 + 4;
						break;
					case '5':
						sum = sum * 10 + 5;
						break;
					case '6':
						sum = sum * 10 + 6;
						break;
					case '7':
						sum = sum * 10 + 7;
						break;
					case '8':
						sum = sum * 10 + 8;
						break;
					case '9':
						sum = sum * 10 + 9;
						break;
					default:
						return sum * sign;                            
				}
			}
			return sum * sign; 
		}
};

int main()
{
	Solution s1, s2;
	long r1 = s1.myAtoi("2147483641");
	cout << "r1 = " << r1 << endl << endl;
	cout << "Num: "<< "2147483648" << "\tresult = " << s2.myAtoi("2147483648") << endl;
}
