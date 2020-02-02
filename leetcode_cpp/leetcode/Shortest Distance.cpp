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
	vector<int> f(n, 0);
	vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
	for (int i = 0; i < n; ++i)
	{
		dist[i][i] = 0;
		cin >> f[i];
	}
	for (int i = 0; i < n; ++i)
	{
		for (int  j = i + 1; j < n; j++)
		{
			dist[i][j] = dist[i][j - 1] + f[j];
		}
	}
	dist[n - 1][0] = f[n - 1];
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; j++)
		{
			int tmpsum = 0;
			for (int k = j;; )
			{
				if (k == i)
				{
					break;
				}
				tmpsum += f[k];
				if (k != n-1)
				{
					++k;
				}
				else if (k == n-1)
				{
					k = 0;
				}
			}
			dist[i][j] = min(dist[i][j], tmpsum);
		}
	}
	int a, b, c;
	cin >> a;
	for (int i = 0; i < a; ++i)
	{
		cin >> b >> c;
		if (b > c)
		{
			swap(b, c);
		}
		cout << dist[b-1][c-1] << endl;
	}
	
	return 0;
}