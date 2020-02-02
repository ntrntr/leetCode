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
vector<int> resdata;
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
		servetime = -1;
	};
};
vector<palyer> data;
int getVip(int time, vector<int>& isVip, vector<int>& leavetime)
{
	for (int i = 0; i < leavetime.size(); ++i)
	{
		if (isVip[i] && leavetime[i] <= time)
		{
			return i;
		}
	}
	return -1;
}
int getNormal(int time, vector<int>& isVip, vector<int>& leavetime)
{
	for (int i = 0; i < leavetime.size(); ++i)
	{
		if (!isVip[i] && leavetime[i] <= time)
		{
			return i;
		}
	}
	return -1;
}
int main()
{
	int n;
	cin >> n;
	int a, b, c, d, e;

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
	vector<int> leaveTime(k, 0);
	p = 8 * 60 * 60;
	vector<int> f;
	resdata.resize(k);
	int allcount = 0;
	for (int count = 0; p < 21 * 60 * 60; ++p)
	{
		while (count < n && data[count].arrivetime <= p)
		{
			f.push_back(count);
			count++;
		}
		for (int i = 0; i < f.size();)
		{
			if (data[f[i]].isVip)
			{
				int ret = getVip(p, isVip, leaveTime);
				if (ret != -1)
				{
					leaveTime[ret] = p + data[f[i]].playingTime;
					data[f[i]].servetime = p;
					f.erase(f.begin() + i);
					resdata[ret]++;
					allcount++;
					continue;
				}
			}
			++i;
		}
		for (int i = 0; i < f.size();)
		{
			int ret = getNormal(p, isVip, leaveTime);
			if (ret != -1)
			{
				leaveTime[ret] = p + data[f[i]].playingTime;
				data[f[i]].servetime = p;
				f.erase(f.begin() + i);
				resdata[ret]++;
				allcount++;
				continue;
			}
			else
			{
				ret = getVip(p, isVip, leaveTime);
				if (ret != -1)
				{
					leaveTime[ret] = p + data[f[i]].playingTime;
					data[f[i]].servetime = p;
					f.erase(f.begin() + i);
					resdata[ret]++;
					allcount++;
					continue;
				}
			}
			++i;
		}
		if (allcount == n)
		{
			break;
		}
	}
	sort(data.begin(), data.end(), [](palyer& a, palyer& b){
		return a.servetime < b.servetime;
	});
	int hh, mm, ss;
	for (auto i : data)
	{
		if (i.servetime == -1)
		{
			continue;
		}
		hh = i.arrivetime / 3600;
		mm = i.arrivetime % 3600 / 60;
		ss = i.arrivetime % 3600 % 60;
		printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", i.arrivetime / 3600, i.arrivetime % 3600 / 60, i.arrivetime % 3600 % 60,
			i.servetime / 3600, i.servetime % 3600 / 60, i.servetime % 3600 % 60, (int)(1.0 * (i.servetime - i.arrivetime) / 60.0 + 0.5));
	}
	bool flag = false;
	for (auto i : resdata)
	{
		if (!flag)
		{
			flag = true;
			cout << i;
		}
		else
		{
			cout << " " << i;
		}

	}
	return 0;
}