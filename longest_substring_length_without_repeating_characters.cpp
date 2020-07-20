#include <iostream>
#include <map>
#include <string>
using namespace std;

class Solution {
	public:
		int lengthOfLongestSubstring(string s)
		{
			map<char, int> mymap;
			map<char, int>::iterator it, tmp;
			int max_len = 0, inx = 0;

			for (int i = 0; i < s.size(); i++)
			{
				it = mymap.find(s[i]);

				if (it == mymap.end())
				{
					mymap[s[i]] = i;
				}
				else if (it->second == inx)
				{
					mymap.erase(it);
					mymap[s[i]] = i;
					inx++;
				}
				else
				{
					inx = it->second + 1;
					for (it = mymap.begin(); it != mymap.end();)
					{
						tmp = it;
						it++;
						if (tmp->second < inx)
							mymap.erase(tmp);

						mymap[s[i]] = i;
					}
				}

				max_len = mymap.size() > max_len ? mymap.size() : max_len;
				//cout << "  i = " << i << "  mymap.size =" << mymap.size() << "\n";
			}       

			return max_len;
		}
};


int main()
{
	string str1 = "pwwkew";
	string str2 = "abcaaadef";
	string str3 = "dvdf";
	string str4 = "qrsvbspk";
	string str5 = "bbbbbbb";
	string str6 = "ohvhjdml";
	Solution s; 
	
	cout << "str = " << str1 << "\tlen = " << s.lengthOfLongestSubstring(str1) << endl;
	cout << "str = " << str2 << "\tlen = " << s.lengthOfLongestSubstring(str2) << endl;
	cout << "str = " << str3 << "\tlen = " << s.lengthOfLongestSubstring(str3) << endl;
	cout << "str = " << str4 << "\tlen = " << s.lengthOfLongestSubstring(str4) << endl;
	cout << "str = " << str5 << "\tlen = " << s.lengthOfLongestSubstring(str5) << endl;
	cout << "str = " << str6 << "\tlen = " << s.lengthOfLongestSubstring(str6) << endl;

}
