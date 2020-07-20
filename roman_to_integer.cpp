#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
	public:
		int romanToInt(string s) {
			map<char, int> roman;
			int i, sum = 0;

			roman['I'] = 1;
			roman['V'] = 5;
			roman['X'] = 10;
			roman['L'] = 50;
			roman['C'] = 100;
			roman['D'] = 500;
			roman['M'] = 1000;

			for (i = 0; i < s.size()-1; i++)
			{
				if (roman[s[i]] < roman[s[i+1]])
					sum -= roman[s[i]];
				else
					sum += roman[s[i]];
			}

			return (sum + roman[s[i]]);
		}
};

int main()
{
	Solution s;
	string str1 = "DXLI";
	string str2 = "MMMCMXCIX";
	cout << "Value of " << str1 << " is " << s.romanToInt(str1) << endl;
	cout << "Value of " << str2 << " is " << s.romanToInt(str2) << endl;
}
