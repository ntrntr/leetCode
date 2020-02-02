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
int main()
{
	int n;
	cin >> n;
	vector<int> f(n);
	vector<int> g(n);
	int pos = 0;
	int count=0;
	int swapcount = 0;
	int t = 0;
	int dcount = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> f[i];
		if (f[i]==i)
		{
			count++;
		}
		if (f[i] == 0)
		{
			pos = i;
		}
	}
	vector<int> visit(n, 0);
	int flag = 0;
	for (int i = 0; i < n; ++i)
	{
		if (!visit[i])
		{
			visit[i] = 1;
			if (f[i] == i)
			{
				continue;
			}
			if (f[i] == f[f[i]])
			{
				if (f[i] == 0 || f[f[i]] == 0)
				{
					flag = 1;
				}
				t += 2;
				visit[f[i]] = 1;
			}
			else
				dcount++;
		}
	}
	if (pos == 0)
	{
		cout << t + 1 + dcount + 1 << endl;
	}
	else if (flag)
	{
		cout << t + 1 + 1 + dcount << endl;
	}
	else
	{
		cout << dcount + t - 1 << endl;
	}
	
	return 0;
}