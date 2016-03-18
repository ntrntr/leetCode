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
int n, m;
vector<vector<int>> length;
vector<vector<int>> timet;
vector<bool> vistied;
int start, mend;
vector<int> d;
vector<int>  dcost;
vector<int> previous;

void dij()
{
	d[start] = 0;
	dcost[start] = 0;
	vector<int> s;
	for (int i = 0; i < n; ++i)
	{
		int minIndex = -1;
		int minLen = INT_MAX;
		for (int j = 0; j < n; ++j)
		{
			if (d[j]<minLen && !vistied[j])
			{
				minLen = d[j];
				minIndex = j;
			}
		}
		
		if (minIndex == -1)
		{
			return;
		}
		vistied[minIndex] = true;
		for (int j = 0; j < n; ++j)
		{
			if (!vistied[j] && length[minIndex][j] != INT_MAX)
			{
				if (d[minIndex] + length[minIndex][j] < d[j])
				{

					previous[j]=(minIndex);
					d[j] = d[minIndex] + length[minIndex][j];
					dcost[j] = d[minIndex] + timet[minIndex][j];
				}
				else if (d[minIndex] + length[minIndex][j] == d[j] && dcost[j] > d[minIndex] + timet[minIndex][j])
				{
					previous[j]=(minIndex);
					d[j] = d[minIndex] + length[minIndex][j];
					dcost[j] = d[minIndex] + timet[minIndex][j];
				}
			}
		}
	}
}
void dij2()
{
	d[start] = 0;
	dcost[start] = 0;
	for (int i = 0; i < n; ++i)
	{
		int minIndex = -1;
		int minLen = INT_MAX;
		for (int j = 0; j < n; ++j)
		{
			if (d[j] < minLen && !vistied[j])
			{
				minLen = d[j];
				minIndex = j;
			}
		}

		if (minIndex == -1)
		{
			return;
		}
		vistied[minIndex] = true;
		for (int j = 0; j < n; ++j)
		{
			if (!vistied[j] && timet[minIndex][j] != INT_MAX)
			{
				if (d[minIndex] + timet[minIndex][j] < d[j])
				{

					previous[j] = (minIndex);
					d[j] = d[minIndex] + timet[minIndex][j];
				//	dcost[j] = d[minIndex] + time[minIndex][j];
				}
				else if (d[minIndex] + timet[minIndex][j] == d[j])
				{
					int count = 0;
					int idx = j;
					while (previous[idx] != start)
					{
						count++;
						idx = previous[idx];
					}
					int count1 = 1;
					idx = minIndex;
					while (previous[idx] != start)
					{
						count1++;
						idx = previous[idx];
					}
					if (count > count1)
					{
						previous[j] = (minIndex);
						d[j] = d[minIndex] + timet[minIndex][j];
					}
					
					//dcost[j] = d[minIndex] + time[minIndex][j];
				}
			}
		}
	}
}
int main1()
{
#ifndef ONLINE_JUDGE
	freopen("D:/1.txt", "r", stdin);
#endif
	cin >> n >> m;
	d = vector<int>(n, INT_MAX);
	previous = vector<int>(n,0);
	dcost = vector<int>(n, INT_MAX);
	vistied = vector<bool>(n, false);
	length = vector<vector<int>>(n, vector<int>(n, INT_MAX));
	timet = vector<vector<int>>(n, vector<int>(n, INT_MAX));
	int aa, bb, cc, dd, ee;
	for (int i = 0; i < m; ++i)
	{	
		cin >> aa >> bb >> cc >> dd >> ee;
		if (cc == 1)
		{
			length[aa][bb] = dd;
			timet[aa][bb] = ee;
		}
		else
		{
			length[aa][bb] = dd;
			timet[aa][bb] = ee;
			length[bb][aa] = dd;
			timet[bb][aa] = ee;
		}
	}
	cin >> start >> mend;
	dij();
	int res1, res2;
	res1 = d[mend];
	int flag = false;
	int kk = mend;
	vector<int> reslength;
	reslength.push_back(mend);
	while (previous[kk] != start)
	{
		reslength.push_back(previous[kk]);
		kk = previous[kk];
	}
	reslength.push_back(start);
	d = vector<int>(n, INT_MAX);
	previous = vector<int>(n, 0);
	dcost = vector<int>(n, INT_MAX);
	vistied = vector<bool>(n, false);
	dij2();
	res2 = d[mend];
	kk = mend;
	vector<int> restime;
	restime.push_back(mend);
	while (previous[kk] != start)
	{
		restime.push_back(previous[kk]);
		kk = previous[kk];
	}
	restime.push_back(start);
	if (reslength == restime)
	{
		cout << "Distance = " << res1 << "; Time = " << res2 << ": ";
		flag = false;
		for (int i = reslength.size() - 1; i >= 0; --i)
		{
			if (!flag)
			{
				cout << reslength[i];
				flag = true;
			}
			else
			{
				cout << " -> " << reslength[i];
			}
		}
		cout << endl;
		return 0;
	}
	flag = false;
	cout << "Distance = " << res1 << ": ";
	for (int i = reslength.size() - 1; i >= 0; --i)
	{
		if (!flag)
		{
			cout << reslength[i];
			flag = true;
		}
		else
		{
			cout << " -> " << reslength[i];
		}
	}
	cout << endl;
	cout << "Time = " << res2 << ": ";
	flag = false;
	for (int i = restime.size() - 1; i >= 0; --i)
	{
		if (!flag)
		{
			cout << restime[i];
			flag = true;
		}
		else
		{
			cout << " -> " << restime[i];
		}
	}
	cout << endl;
	return 0;
}