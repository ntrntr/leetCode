#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <unordered_map>
#include <set>
using namespace std;
class Solution {
public:
	string removeDuplicateLetters(string s) {
		vector<string> res;
		int size;
		set<char> f(s.begin(), s.end());
		size = f.size();
		res.clear();
		vector<char> tmp;
		dfs(0, tmp, s, size, res);
		sort(res.begin(), res.end());
		return res[0];
	}
	void dfs(int i, vector<char>& tmp, string& s, int size, vector<string>& res)
	{
		if (i == s.size())
		{
			if (tmp.size() == size)
			{
				string tmp(tmp.begin(), tmp.end());
				res.push_back(tmp);
			}
			
			return;
		}
		auto it = find(tmp.begin(), tmp.end(), s[i]);
		if ( it != tmp.end())
		{
			//noadd

			dfs(i + 1, tmp, s, size, res);
		}
		else
		{
			
			dfs(i + 1, tmp, s, size, res);
			tmp.push_back(s[i]);
			dfs(i + 1, tmp, s, size, res);
			tmp.pop_back();
		}
			
	}
public:
	
};
int main()
{
	Solution s;
	cout << s.removeDuplicateLetters("bcabc") << endl;
	return 0;
}