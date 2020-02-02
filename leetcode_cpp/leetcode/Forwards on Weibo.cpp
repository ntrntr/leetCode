#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <unordered_map>
#include <limits.h>
#include <set>
using namespace std;
int n, level;
map<int, set<int>> f;
void dfs(set<int>& ff, int l, vector<int>& visit, int& res)
{
	if (l > level)
	{
		return;
	}
	for (auto i:ff)
	{
		if (!visit[i])
		{
			++res;
			visit[i] = 1;
			
		}
	}
	for (auto i:ff)
	{
		dfs(f[i], l + 1, visit, res);
	}
}
int getNum(int a)
{
	int res = 0;
	vector<int> visit(n+1, 0);
	visit[a] = 1;
	dfs(f[a], 1, visit, res);
	return res;
}

int main()
{
	cin >> n >> level;
	int a, b;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a;
		for (int j = 0; j < a; ++j)
		{
			cin >> b;
			f[b].insert(i);
		}
	}
	cin >> a;
	for (int i = 0; i < a;++i)
	{
		cin >> b;
		cout << getNum(b) << endl;
	}

	return 0;
}