#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
using namespace std;
#define MAXLEN 100000000
int v, q;
vector<int> dis;
vector<bool> visited;
void Dijkstart(int s, int e, vector<vector<int>>& G)
{
	visited = vector<bool>(v, false);
	dis = vector<int>(v, MAXLEN);
	dis[s] = 0;
	for (int i = 0; i < v; ++i)
	{
		int u = -1;
		int minlen = MAXLEN;
		for (int j = 0; j < v; ++j)
		{
			if (!visited[j] && dis[j] < MAXLEN )
			{
				minlen = dis[j];
				u = j;
			}
		}
		if (u == -1 || u == e)
		{
			return;
		}
		visited[u] = true;
		for (int j = 0; j < v; ++j)
		{
			if (G[u][j] < MAXLEN && !visited[j])
			{
				if (dis[j] > dis[u] + G[u][j])
				{
					dis[j] = dis[u] + G[u][j];
				}
			}
		}
	}
	return;
}
int main()
{
	
	cin >> v >> q;
	vector<vector<int>> G(v, vector<int>(v, MAXLEN));
	for (int i = 0; i < v - 1; ++i)
	{
		G[i][i + 1] = 1;
	}
	int a, b;
	while (q--)
	{
		cin >> a >> b;
		Dijkstart(a - 1, b - 1, G);
		if (dis[b-1] < MAXLEN)
		{
			cout << dis[b - 1] << endl;
		}
		else
		{
			cout << "-1" << endl;
			
		}
		G[a - 1][b - 1] = 1;
	}
	return 0;
}