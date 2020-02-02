#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <unordered_map>
#include <limits.h>
#include <queue>
using namespace std;
int m, n, l, t;
struct xyz
{
	int x, y, z;
	xyz(){};
	xyz(int i, int j, int k) :x(i), y(j), z(k){};
};
queue<xyz> que;
void dfs(int& count, vector<vector<vector<int>>>& volume, vector<vector<vector<int>>>& visit)
{
	while (!que.empty())
	{
		xyz tmp = que.front();
		que.pop();
		
		int i = tmp.x, j = tmp.y, k = tmp.z;
		if (i < 0 || j < 0 || k < 0 || i >= l || j >= m || k >= n || visit[i][j][k])
		{
			continue;;
		}
		visit[i][j][k] = 1;
		if (volume[i][j][k] == 0)
		{
			continue;
		}
		count++;
		
		que.push(xyz(i - 1, j, k));
		que.push(xyz(i + 1, j, k));
		que.push(xyz(i , j - 1, k));
		que.push(xyz(i , j + 1, k));
		que.push(xyz(i , j, k - 1));
		que.push(xyz(i , j, k + 1));
		//dfs(i - 1, j, k, count, volume, visit);
		//dfs(i + 1, j, k, count, volume, visit);
		//dfs(i, j - 1, k, count, volume, visit);
		//dfs(i, j + 1, k, count, volume, visit);
		//dfs(i, j, k - 1, count, volume, visit);
		//dfs(i, j, k + 1, count, volume, visit);
	}
	
	return;
}
int main()
{
	
	cin >> m >> n >> l >> t;
	vector<vector<vector<int>>> volume(l, vector<vector<int>>(m, vector<int>(n, 0)));
	vector<vector<vector<int>>> visit(l, vector<vector<int>>(m, vector<int>(n, 0)));
	for (int i = 0; i < l; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			for (int k = 0; k < n; ++k)
			{
				cin >> volume[i][j][k];
			}
		}
	}
	int res = 0;
	for (int i = 0; i < l; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			for (int k = 0; k < n; ++k)
			{
				int count = 0;
				if (!visit[i][j][k] && volume[i][j][k]==1)
				{
					que.push(xyz(i, j, k));
					dfs(count, volume, visit);
				}
				if (count >= t)
				{
					res += count;
				}
			}
		}
	}
	cout << res << endl;
	return 0;
}