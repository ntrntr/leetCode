#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
	bool wordPattern(string pattern, string str) {

		unordered_map<char, string> myMap;
		unordered_map<string, char> myMap1;
		vector<string> f;
		string::size_type found = 0;
		string::size_type t = 0;
		while((t = str.find(" ", found, 1)) != string::npos)
		{
			f.push_back(str.substr(found, t - found));
			found = t + 1;
		}
		f.push_back(str.substr(found));
		if(pattern.size() != f.size())
		{
			return pattern == str;
		}
		for(int i = 0; i < pattern.size(); ++i)
		{
			if(myMap.find(pattern[i]) == myMap.end() && myMap1.find(f[i]) == myMap1.end())
			{
				myMap[pattern[i]] = f[i];
				myMap1[f[i]] = pattern[i];
			}
			else
			{
				if(myMap[pattern[i]] != f[i] || myMap1[f[i]] != pattern[i])
				{
					return false;
				}
			}
		}
		return true;
	}
};
int main()
{
	Solution s;
	cout<<s.wordPattern("abba",
		"dog dog dog dog");
	return 0;
}