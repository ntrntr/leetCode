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
struct palyer
{
	int arrivetime;
	int servetime;
	int playingTime;
	bool isVip;
	palyer(){};
	palyer(int a, int b, int c, int d, int e){
		arrivetime = c + b * 60 + a * 60 * 60;
		playingTime = min(d * 60, 2 * 60 * 60);
		isVip = (e == 1 ? true : false);
	};
};
int main()
{
	int n;
	cin >> n;
	int a, b, c, d, e;
	vector<palyer> data;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d:%d:%d %d %d", &a, &b, &c, &d, &e);
		data.push_back(palyer(a, b, c, d, e));
	}
	sort(data.begin(), data.end(), [](palyer& a, palyer& b){
		return a.arrivetime < b.arrivetime;
	});
	int k, m, p;
	cin >> k >> m;
	vector<int> isVip(k, 0);
	int tmp;
	for (int i = 0; i < m; ++i)
	{
		cin >> tmp;
		isVip[tmp - 1] = 1;
	}
	vector<vector<int>> tableData(k);
	int tablecount = 0, vipcount = 0;
	int pp = 8 * 60 * 60;
	int playercount = 0;
	queue<int> vipqueue;
	queue<int> cqueue;
	vector<int> tableleavetime;
	for (;playercount < n;)
	{
		if (data[playercount].arrivetime > pp)
		{
			++pp;
			continue;
		}
		if (data[playercount].arrivetime == pp)
		{
			if (data[playercount].isVip)
			{
				vipqueue.push(playercount);
			}
			else
			{
				cqueue.push(playercount);
			}
			playercount++;
		}
	}
	
	return 0;
}