#include <iostream>
#include <sstream>
#include <string>
#include <map>
using namespace std;

class Solution {
	public:
		bool wordPattern(string pattern, string str) {
			if (pattern == "" || str == "")
				return false;
			map<char, string> dict;
			istringstream input(str);
			map<char, string>::iterator it;
			int i = 0, psize = pattern.size();
			for (string word; input >> word; i++)
			{
				it = dict.find(pattern[i]);
				if (it != dict.end())
				{
					if (it->second != word)
						return false;
				}
				else
					dict[pattern[i]] = word;
			}
			return (i == psize);
		}
};

int main()
{
	Solution s1;
	cout << "s1 result = " << s1.wordPattern("abba", "dog cat cat dog") << endl;
	return 0;
}
