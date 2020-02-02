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
int c, n, sp, m;
vector<vector<int>> link;
vector<bool> visited;
vector<int> allpath;
vector<int> bikes;
int minlen = INT_MAX;
int minneedcar = INT_MAX;
int minavailable = INT_MAX;
void dfs(int start, int end, int len, vector<int>& path, int needcar, int available)
{
	if (start == end)
	{
		if (len < minlen)
		{
			minlen = len;
			allpath = path;
			minneedcar = needcar;
			minavailable = available;
		}
		else if (len == minlen)
		{
			if (minneedcar > needcar)
			{
				allpath = path;
				minneedcar = needcar;
				minavailable = available;
			}
			else if (minneedcar == needcar && minavailable > available)
			{
				allpath = path;
				minneedcar = needcar;
				minavailable = available;
			}
			
		}

		return;
	}
	for (int  i = 0; i < n + 1; i++)
	{
		if (!visited[i] && link[start][i] != INT_MAX)
		{
			path.push_back(i);
			visited[i] = true;
			if (bikes[i] >= c/2)
			{
				dfs(i, end, len + link[start][i], path, needcar, available + bikes[i] - c / 2);
			}
			else
			{
				if (c / 2 - bikes[i] < available)
				{
					dfs(i, end, len + link[start][i], path, needcar, available - (c / 2 - bikes[i]));
				}
				else
				{
					dfs(i, end, len + link[start][i], path, needcar + c / 2 - bikes[i] - available, 0);
				}
				
			}
			
			path.pop_back();
			visited[i] = false;

		}
	}
}
int main()
{
	while (cin >> c >> n >> sp >> m)
	{
		link = vector<vector<int>>(n + 1, vector<int>(n + 1, INT_MAX));
		visited = vector<bool>(n + 1, false);
		bikes.resize(n + 1);
		for (int i = 1; i <= n; ++i)
		{
			cin >> bikes[i];
		}
		int a, b, c;
		for (int i = 0; i < m; ++i)
		{
			cin >> a >> b >> c;
			link[a][b] = c;
			link[b][a] = c;
		}
		vector<int> path;
		path.push_back(0);
		visited[0] = true;
		dfs(0, sp, 0, path, 0, 0);
		cout << minneedcar << " ";
		for (int i = 0; i < allpath.size(); ++i)
		{
			if (i == 0)
			{
				cout << allpath[i];
			}
			else
				cout << "->" << allpath[i];
		}
		cout << " " << minavailable << endl;
	}

	
	return 0;
}