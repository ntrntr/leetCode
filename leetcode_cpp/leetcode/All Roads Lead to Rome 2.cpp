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
int mincost = INT_MAX;
int maxHappniess = INT_MIN;
vector<string> resPath;
int mycount = 0;
string dst = "ROM";
int N, K;
int destInt;
vector<int> father;
vector<int> visit;
vector<int> happyData;
vector<vector<int>> link;
map<string, int> cityToNum;
map<int, string> numToCity;
vector<int> totalCost, happiness, nextCity, waycount, cityRouteNums;
void dij()
{
	totalCost[0] = 0;
	waycount[0] = 1;
	cityRouteNums[0] = 0;
	int k = -1;
	for (int i = 0; i < N; ++i)
	{
		k = -1;
		for (int j = 0; j < N; ++j)
		{
			if (!visit[j] && (k < 0 || totalCost[j] < totalCost[k]))
			{
				k = j;
			}
		}
		visit[k] = 1;
		for (int j = 0; j < N; ++j)
		{
			if (!visit[j] && link[k][j] > 0)
			{
				int tmp = totalCost[k] + link[k][j];
				if (tmp < totalCost[j])
				{
					totalCost[j] = tmp;
					happiness[j] = happiness[k] + happyData[j];
					nextCity[j] = k;
					waycount[j] = waycount[k];
					cityRouteNums[j] = cityRouteNums[k] + 1;
				}
				else if (tmp == totalCost[j])
				{
					waycount[j] += waycount[k];
					if (happiness[j] < (happiness[k] + happyData[j])
						|| (happiness[j] == happiness[k] + happyData[j]
						&& cityRouteNums[j] > cityRouteNums[k] + 1)) {
						nextCity[j] = k;
						happiness[j] = happiness[k] + happyData[j];
						cityRouteNums[j] = cityRouteNums[k] + 1;
					}
				}
			}
		}
	}
}
int main()
{
	string src;
	cin >> N >> K >> src;
	visit = vector<int>(N, 0);
	happyData = vector<int>(N, 0);
	totalCost = vector<int>(N, INT_MAX);
	happiness = vector<int>(N, 0);
	waycount = vector<int>(N, 0);
	cityRouteNums = vector<int>(N, INT_MAX);
	nextCity = vector<int>(N, -1);
	link = vector<vector<int>>(N, vector<int>(N, 0));
	cityToNum[src] = 0;
	numToCity[0] = src;
	string tmp, tmp1;
	int tmpHappy, cost;
	for (int i = 1; i < N; ++i)
	{
		cin >> numToCity[i] >> happyData[i];
		cityToNum[numToCity[i]] = i;
	}
	for (int i = 0; i < K; ++i)
	{
		cin >> tmp >> tmp1 >> cost;
		int a = cityToNum[tmp], b = cityToNum[tmp1];
		link[a][b] = cost;
		link[b][a] = cost;
	}
	destInt = cityToNum[dst];
	dij();
	cout << waycount[destInt] << " " << totalCost[destInt] << " " << happiness[destInt] <<" "<< (int)(1.0 * happiness[destInt] / cityRouteNums[destInt]) << endl;
	int i = destInt;
	vector<string> cityres;
	while (i != -1)
	{
		cityres.push_back(numToCity[i]);
		i = nextCity[i];
	}
	for (int i = cityres.size() - 1; i > 0; i--)
	{
		cout << cityres[i] << "->";
	}
	cout << cityres[0] << endl;
	return 0;
}