#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <unordered_map>
#include <limits.h>
using namespace std;
vector<int> visited;
vector<vector<int>> dist;
vector<vector<int>> cost;
int mindist = INT_MAX;
int mincost = INT_MAX;
vector<int> res;
void dfs(int s, int e, int dis, int cos, vector<int>& path)
{
	if (s == e)
	{
		if (dis < mindist)
		{
			mindist = dis;
			mincost = cos;
			res.assign(path.begin(), path.end());
		}
		else if (dis == mindist && mincost > cos)
		{
			mincost = cos;
			res.assign(path.begin(), path.end());
		}
	}
	for (int i = 0; i < dist.size(); ++i)
	{
		if (i != s && !visited[i] && dist[s][i] != INT_MAX)
		{
			visited[i] = 1;
			path.push_back(i);
			dfs(i, e, dis + dist[s][i], cos + cost[s][i], path);
			path.pop_back();
			visited[i] = 0;
		}
		if (i == s)
		{
			continue;
		}
	}
}
int main()
{
	int n, m, s, d;
	cin >> n >> m >> s >> d;
	dist=vector<vector<int>>(n, vector<int>(n, INT_MAX));
	cost=vector<vector<int>>(n, vector<int>(n, INT_MAX));
	int a, b, c, dd;
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b >> c >> dd;
		dist[a][b] = c;
		dist[b][a] = c;
		cost[a][b] = dd;
		cost[b][a] = dd;
	}
	visited = vector<int>(n, 0);
	visited[s] = 1;
	vector<int> path;
	path.push_back(s);
	dfs(s, d,0,0,path);
	int flag = false;
	for (auto i:res)
	{
		if (!flag)
		{
			cout << i;
			flag = true;
		}
		else
		{
			cout << " " << i;
		}
		
	}
	cout << " " << mindist << " " << mincost << endl;
	return 0;
}