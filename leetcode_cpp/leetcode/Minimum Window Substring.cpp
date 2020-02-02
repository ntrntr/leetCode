#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
//class Solution {
//public:
//	string minWindow(string s, string t) {
//		const int n = s.size();
//		const int m = t.size();
//		vector<int> f(n,0);
//		vector<int> g(300,0);
//		vector<int> path;
//		string res;
//		for (auto i:t)
//		{
//			++g[i];
//		}
//		for (int i = 0; i < n; ++i)
//		{
//			if (g[s[i]] > 0)
//			{
//				f[i] = g[s[i]];
//				path.push_back(i);
//			}
//		}
//		for (int i = 0; i < path.size(); ++i)
//		{
//			vector<int> tmp(g.begin(),g.end());
//			int tmpcount = m;
//			if (path.size() - i < m)
//			{
//				break;
//			}
//			for (int j = i; j < path.size(); ++j)
//			{
//				if (!res.empty() && res.size() < ( path[j] - path[i] + 1 ))
//				{
//					break;
//				}
//				if (tmp[s[path[j]]] > 0)
//				{
//					--tmp[s[path[j]]];
//					--tmpcount;
//				}
//				if (tmpcount == 0)
//				{
//					if (res.empty())
//					{
//						res = s.substr(path[i], path[j] - path[i] + 1);
//						//cout<<res<<endl;
//					}
//					else if (res.size() > ( path[j] - path[i] + 1))
//					{
//						res = s.substr(path[i], path[j] - path[i] + 1);
//						//cout<<res<<endl;
//					}
//					break;
//				}
//			}
//		}
//		return res;
//	}
//};
class Solution {
public:
	string minWindow(string s, string t) {
		vector<int> need(300, 0);
		vector<int> appear(300, 0);
		for (auto i:t)
		{
			need[i]++;
		}
		int begin = 0, end = 0;
		int count = 0;
		int minWidth = INT_MAX;
		int minstart = 0;
		for (end = 0; end < s.size(); ++end)
		{
			if (need[s[end]] > 0)
			{
				appear[s[end]]++;
				if (appear[s[end]] <= need[s[end]])
				{
					count++;
				}
			}

			if (count == t.size())
			{
				while (appear[s[begin]] > need[s[begin]] || need[s[begin]] == 0)
				{
					appear[s[begin]]--;
					begin++;
				}
				if (minWidth > (end - begin + 1) )
				{
					minWidth = end - begin + 1;
					minstart = begin;
				}
			}
		}
		if (minWidth == INT_MAX)
		{
			return "";
		}
		return s.substr(minstart, minWidth);
	}
};
int main()
{
	Solution s;
	
		cout<<s.minWindow("ADOBECODEBANC", "ABC")<<endl;
	return 0;
}


