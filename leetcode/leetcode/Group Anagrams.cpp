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
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> res;
		unordered_map<string, vector<string>> myMap;
		const int size = strs.size();
		for (int i = 0; i < size; ++i)
		{
			string tmp = strs[i];
			sort(tmp.begin(), tmp.end());
			int flag = 0;
			myMap[tmp].push_back(strs[i]);
		}
		for (auto& i:myMap)
		{
			sort(i.second.begin(), i.second.end());
			res.push_back(i.second);
		}
		return res;
	}
};
int main()
{
	Solution s;
	string a [] = {"eat", "tea", "tan", "ate", "nat", "bat"};
	vector<string> ss(a, a + 6);
	for (auto i: s.groupAnagrams(ss))
	{
		for (auto j : i)
		{
			cout<<j<<" ";
		}
		cout<<endl;
	}
	return 0;
}