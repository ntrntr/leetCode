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
#include <deque>
using namespace std;
int n, m, k, q;
vector<deque<int>> f;
int findpos()
{
	int minpos = -1;
	int minQueue = m;
	for (int i = 0; i < f.size(); ++i)
	{
		if (f[i].size() < minQueue)
		{
			minQueue = f[i].size();
			minpos = i;
		}
	}
	return minpos;
}
int popf()
{
	int minTime = f[0].front();
	for (int i = 1; i < f.size(); ++i)
	{
		if (f[i].front() < minTime)
		{
			minTime = f[i].front();
		}
	}
	for (int i = 0; i < f.size(); ++i)
	{
		f[i].front() -= minTime;
		if (f[i].front() == 0)
		{
			f[i].pop_front();
		}
	}
	return minTime;
}
int main()
{
	
	cin >> n >> m >> k >> q;
	vector<int> customersTime(k+1,0);
	
	vector<int> leaveTime(k + 1, -1);
	f.resize(n);
	for (int i = 1; i <= k; ++i)
	{
		cin >> customersTime[i];
	}
	int time = 0;
	int count = 1;
	int c;
	while (count <= k)
	{
		if ((c = findpos()) != -1)
		{
			int sum = 0;
			for (int i = 0; i < f[c].size(); ++i)
			{
				sum += f[c][i];
			}
			f[c].push_back(customersTime[count]);
			leaveTime[count] = time + customersTime[count] + sum;
			++count;
		}
		else
		{
			time += popf();
		}
		
	}
	for (int i = 0; i < q; ++i)
	{
		int c;
		cin >> c;
		if (leaveTime[c]>540)
		{
			cout << "Sorry" << endl;
		}
		else
		printf("%02d:%02d\n", 8 + leaveTime[c] / 60, leaveTime[c] % 60);
	}
	return 0;
}