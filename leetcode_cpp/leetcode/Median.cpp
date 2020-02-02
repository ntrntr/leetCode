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
	
	long int n;
	cin >> n;
	vector<long int> f(n);
	for (long int i = 0; i < n; ++i)
	{
		scanf("%ld", &f[i]);
		//cin >> f[i];
	}
	long int m;
	cin >> m;
	vector<long int> g(m);
	for (long int i = 0; i < m; ++i)
	{
		scanf("%ld", &g[i]);
		//cin >> g[i];
	}
	long int mid = (n + m + 1) / 2 - 1;
	long int i = 0, j = 0;
	for (; i + j < mid;)
	{
		if (i == n)
		{
			++j;
		}
		else if (j == m)
		{
			++i;
		}
		else
		{
			if (f[i] < g[j])
			{
				++i;
			}
			else
			{
				++j;
			}
		}

	}
	if (i < n && j < m)
	{
		cout << (f[i] < g[j] ? f[i] : g[j]) << endl;
		return 0;
	}
	if (i == n)
	{
		cout << g[j] << endl;
	}
	else
	{
		cout << f[i] << endl;
	}
	return 0;
}