#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <unordered_map>
#include <limits.h>
#include <functional>
using namespace std;
struct customer
{
	int arrivetime;
	int servertime;
	int leavetime;
	int last;
	customer(){};
	customer(int a, int b) :arrivetime(a), last(b){};
};
int starttime = 8 * 60 * 60;
vector<int> window;
int n, k;
int getServeTime(int arrivetime)
{
	if (window.size() < k)
	{
		
	}
	else if (window.size() == k)
	{
		sort(window.begin(), window.end(), greater<int>());
		starttime = window.back();
		window.pop_back();
	}
	if (arrivetime < starttime)
	{
		return starttime;
	}
	else
		return arrivetime;
}
int main()
{
	
	cin >> n >> k;
	vector<customer> f;
	int a, b, c, d;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d:%d:%d %d", &a, &b, &c, &d);
		int time = c + b * 60 + a * 60 * 60;
		if (time > 17 * 60 * 60)
		{
		
		}
		else
		{
			f.push_back(customer(time, d));
		}
	}
	sort(f.begin(), f.end(), [](customer& a, customer& b)->bool{ return a.arrivetime < b.arrivetime; });
	int sum = 0;
	for (int i = 0; i < f.size(); ++i)
	{
		f[i].servertime = getServeTime(f[i].arrivetime);
		f[i].leavetime = f[i].servertime + f[i].last * 60;
		window.push_back(f[i].leavetime);
		sum += f[i].servertime - f[i].arrivetime;
	}
	printf("%.1f\n", sum / 60.0 / f.size());
	return 0;
}