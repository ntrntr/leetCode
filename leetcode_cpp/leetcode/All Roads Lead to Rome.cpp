#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <limits.h>
#include <unordered_map>
using namespace std;
const int MYSIZE = 17577;
int leastcost = INT_MAX;
int minCostCount = 0;
int maxhappiness = INT_MIN;
vector<int> respath;
char dst[4] = "ROM";
int charToInt(char src[])
{
	int res = 0;
	for (int i = 0; i < 3;++i)
	{
		res = res * 26 + (src[i] - 'A');
	}
	return res;
}
void dfs(int cur, int cost, int happiness, vector<int>& happyData, vector<vector<int>>& link, vector<int>& visit, vector<int>& path)
{
	if (cur == charToInt(dst))
	{
		if (leastcost > cost)
		{
			leastcost = cost;
			minCostCount = 1;
			maxhappiness = happiness;
			respath = path;
			return;
		}
		else if (leastcost == cost)
		{
			if (maxhappiness < happiness)
			{
				leastcost = cost;
				minCostCount++;
				maxhappiness = happiness;
				respath = path;
				return;
			}
			else if (maxhappiness == happiness)
			{
				if (path.size() < respath.size())
				{
					leastcost = cost;
					minCostCount++;
					maxhappiness = happiness;
					respath = path;
					return;
				}
			}
		}
		return;
	}
	if (cost > leastcost)
	{
		return;
	}
	for (int i = 0; i < MYSIZE; ++i)
	{
		if (link[cur][i] != -1 && !visit[i])
		{
			path.push_back(i);
			visit[i] = 1;
			dfs(i, cost + link[cur][i], happiness + happyData[i], happyData, link, visit, path);
			path.pop_back();
			visit[i] = 0;
		}
	}
}
string intToChar(int x)
{
	string res = "";
	res.push_back('A' + x / (26 * 26));
	x = x % (26 * 26);
	res.push_back('A' + x / 26);
	res.push_back('A' + x % 26);
	return res;
}
int main()
{
	int N, K;
	char src[4];
	char tmp[4],tmp1[4];
	int happy;
	int cost;
	cin >> N >> K >> src;
	vector<int> happyData(MYSIZE, 0);
	vector<int> visit(MYSIZE, 0);
	vector<vector<int>> link(MYSIZE, vector<int>(MYSIZE, -1));
	for (int i = 0; i < N - 1; ++i)
	{
		cin >> tmp >> happy;
		happyData[charToInt(tmp)] = happy;
	}
	
	for (int i = 0; i < K; ++i)
	{
		cin >> tmp >> tmp1 >> cost;
		int a = charToInt(tmp), b = charToInt(tmp1);
		link[a][b] = link[b][a] = cost;
	}
	visit[charToInt(src)] = 1;
	vector<int> path;
	path.push_back(charToInt(src));
	dfs(charToInt(src), 0, 0, happyData, link, visit, path);
	cout << minCostCount << " " << leastcost << " " << maxhappiness << " " << (int)(1.0 * maxhappiness / (respath.size() - 1)) << endl;
	for (int i = 0; i < respath.size(); ++i)
	{
		if (i == respath.size() - 1)
		{
			//cout << (respath[i]) << endl;
			cout << intToChar(respath[i]) << endl;
		}
		else
		{
			//cout << (respath[i]) << "->";
			cout << intToChar(respath[i]) << "->";
		}
			
	}
	return 0;
}