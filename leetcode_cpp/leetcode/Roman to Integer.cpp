#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;
class Solution {
public:
	int romanToInt(string s) {
		int res = 0;
		/*const int radix[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
		const string symbom[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"} ;
		unordered_map<string, int> myMap;
		for (int i = 0; i < 13; ++i)
		{
		myMap[symbom[i]] = radix[i];
		}
		const int size = s.size();
		for (int i = 0; i < size;)
		{
		if (i <= size - 2)
		{
		string tmp(s.begin() + i, s.begin() + i + 2);
		if (myMap.find(tmp) != myMap.end())
		{
		res += myMap[tmp];
		i += 2;
		}
		else
		{
		string aa(s.begin() + i, s.begin() + i + 1);
		res += myMap[aa];
		i += 1;
		}
		}
		else
		{
		string aa(s.begin() + i, s.begin() + i + 1);
		res += myMap[aa];
		i += 1;
		}
		}*/
		for (int i = 0; i < s.size(); ++i)
		{
			if (i > 0 && mymap(s[i]) > mymap(s[i - 1]))
			{
				res += mymap(s[i]) - mymap(s[i-1]) * 2;
			}
			else
				res += mymap(s[i]);
		}
		return res;
	}
	inline int mymap(char a)
	{
		switch (a)
		{
		case 'I':
			return 1;
		case 'V':
			return 5;
		case 'X':
			return 10;
		case  'L':
			return 50;
		case 'C':
			return 100;
		case 'D':
			return 500;
		case  'M':
			return 1000;


		default:
			return 0;
		}
	}
};
int main()
{
	Solution s;
	string tmp;
	while(cin>>tmp)
	{
	cout<<s.romanToInt(tmp)<<endl;
	}

	
	return 0;
}