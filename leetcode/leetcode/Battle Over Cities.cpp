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
int tree[1000];
int findRoot(int x)
{
	if (tree[x] == -1)
	{
		return x;
	}
	else
	{
		int tmp = findRoot(tree[x]);
		tree[x] = tmp;
		return tmp;
	}
}
struct w
{
	int x, y;
}way[500000];
int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < m; ++i)
	{
		cin >> way[i].x >> way[i].y;
	}
	while (k--)
	{
		for (int i = 1; i <= n; ++i)
		{
			tree[i] = -1;
		}
		int c;
		cin >> c;
		for (int i = 0; i < m; ++i)
		{
			if (way[i].x == c || way[i].y == c)
			{
				continue;
			}
			int rx = findRoot(way[i].x);
			int ry = findRoot(way[i].y);
			if (rx != ry)
			{
				tree[rx] = ry;
			}
			

		}
		int group = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (tree[i] == -1)
			{
				group++;
			}
		}
		cout << group - 2 << endl;
	}
	return 0;
}