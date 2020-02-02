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
int cccc;
vector<vector<bool>> f;
vector<bool> visited;
vector<int> len;
int n;
int getlen(int x, vector<vector<bool>>& link, vector<bool>& visited)
{
	int res = 0;
	int tmp = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (i == x || visited[i] == true || link[x][i] == false)
		{
			continue;
		}
		visited[i] = true;
		tmp = 1 + getlen(i, link, visited);
		visited[i] = false;
		if (tmp > res)
		{
			res = tmp;
		}
	}
	return res;
}
vector<int> com;
int getNum(int x)
{
	if (com[x] != x)
	{
		com[x] = getNum(com[x]);
	}
		return com[x];
}
void link(int a, int b)
{
	int ta = getNum(a);
	int tb = getNum(b);
	if (ta != tb)
	{
		com[ta] = tb;
		--cccc;
	}
}
int maxlen = 0;
set<int> res, rrs;
void dfs(int a, int step)
{
	if (step > maxlen)
	{
		res.clear();
		res.insert(a);
		maxlen = step;
	}
	else if (step == maxlen)
	{
		res.insert(a);
	}
	for (int i = 1; i <= n; ++i)
	{
		if (!visited[i] && f[a][i])
		{
			visited[i] = true;
			dfs(i, step + 1);
			visited[i] = false;
		}
	}
}
int main()
{
	
	cin >> n;
	int a, b;
	 f= vector<vector<bool>>(n + 1, vector<bool>(n + 1, false));
	visited = vector<bool>(n + 1, false);
	len = vector<int>(n + 1, 1);
	com = vector<int>(n + 1, -1);
	cccc = n - 1;
	for (int i = 0; i <= n; ++i)
	{
		com[i] = i;
	}
	
	for (int i = 0; i < n - 1; ++i)
	{
		cin >> a >> b;
		f[a][b] = true;
		f[b][a] = true;
		link(a, b);
	}

	if (cccc !=  0)
	{
		cout << "Error: " << cccc + 1 << " components" << endl;
		return 0;
	}
	visited[1] = true;
	dfs(1, 1);
	visited[1] = false;
	rrs.insert(res.begin(), res.end());
	visited[*res.begin()] = true;
	dfs(*res.begin(), 1);
	rrs.insert(res.begin(), res.end());

	for (auto i:rrs)
	{
		cout << i << endl;
	}
	return 0;
}