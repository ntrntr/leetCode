#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <unordered_map>
using namespace std;
int minNeedBikeAdjust = 0x7FFFFFFF;
int minNeedReceive = 0x7FFFFFFF;
int minsumDis = 0x7FFFFFFF;
vector<int> res;
int cmax, N, sp, m;
vector<int> numberOfBike;
void dfs(int cur, int bikes,int offset, int dis, vector<int>& path, vector<int>& visit, vector<vector<int>>& link)
{
	if (dis > minsumDis)
	{
		return;
	}
	if (cur == 0)
	{
		if ((dis < minsumDis) || (dis == minsumDis && minNeedBikeAdjust > bikes))
		{
			res = path;
			minsumDis = dis;
			minNeedBikeAdjust = bikes;
			minNeedReceive = offset;
			return;
		}
		return;
	}
	for (int i = 0; i <= N; ++i)
	{
		if (link[cur][i] != -1 && !visit[i])
		{
			visit[i] = 1;
			path.push_back(i);
			int tmp = bikes + cmax / 2 - numberOfBike[cur];
			if (tmp < 0)
			{	
				dfs(i, 0, offset - tmp, dis + link[cur][i], path, visit, link);
			}
			else
			{
				dfs(i, tmp, offset, dis + link[cur][i], path, visit, link);
			}
			path.pop_back();
			visit[i] = 0;
		}
	}
}
int main()
{
	cin >> cmax >> N >> sp >> m;
	numberOfBike = vector<int>(N + 1, 0);
	for (int i = 1; i <= N; ++i)
	{
		cin >> numberOfBike[i];
	}
	vector<vector<int>> link(N + 1, vector<int>(N + 1, -1));
	int a, b, c;
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b >> c;
		link[a][b] = link[b][a] = c;
	}
	vector<int> visit(N + 1, 0);
	visit[sp] = 1;
	int cur = sp;
	int needBikeAdjust = 0;
	int sumDis = 0;
	vector<int> path;
	path.push_back(cur);
	visit[cur] = 1;
	dfs(cur, needBikeAdjust, 0,sumDis, path, visit, link);
	cout << minNeedBikeAdjust << " ";
	for (auto i = res.rbegin(); i != res.rend(); ++i)
	{
		if (i == res.rend()-1)
		{
			cout << *i << " ";
		}
		else
		cout << *i << "->";
	}
	cout << minNeedReceive << endl;
	return 0;
}