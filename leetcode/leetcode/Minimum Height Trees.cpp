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
	vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
		vector<int> res;
		map<int, vector<int>> f;
		vector<int> used(n, 0);
		for (auto i:edges)
		{
			f[i.first].push_back(i.second);
			f[i.second].push_back(i.first);
		}
		int maxlen = INT_MAX;
		for (auto i:f)
		{
			cout << i.first << " ";
			for (auto j:i.second)
			{
				cout << j << " ";
			}
			cout << endl;
		}
		for (int i = 0; i < n; ++i)
		{
			fill(used.begin(), used.end(), 0);
			int len = getLen(i, f, used);
			if (maxlen >  len)
			{
				res.clear();
				res.push_back(i);
				maxlen = len;
			}
			else if (maxlen == len)
			{
				res.push_back(i);
			}
		}
		for (auto i:res)
		{
			cout << i << " ";
		}
		return res;
	}
	int getLen(int root, map<int, vector<int>>& f, vector<int>& used)
	{
		used[root] = 1;
		int len = 0;
		for (auto i:f[root])
		{
			if (!used[i])
			{
				len = max(len, getLen(i, f, used) + 1);
			}
		}
		return len;
	}
};
int main()
{
	Solution s;
	vector<pair<int, int>> edges{ make_pair(0, 3), make_pair(1, 3), make_pair(2, 3), make_pair(4, 3),make_pair(5, 4) };
	s.findMinHeightTrees(4, edges);
	return 0;
}