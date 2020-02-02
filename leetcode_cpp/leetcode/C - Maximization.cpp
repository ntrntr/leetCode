#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;
int h, w, x, k;
struct node
{

	int pos;
	int res;
	int delta;
	node(){}
	node(int i, int sum, int d):pos(i), res(sum),delta(d){}
};
int main()
{
	cin>>h>>w>>x>>k;
	vector<vector<int>> f(h, vector<int>(w));
	vector<node> row(h);
	vector<node> col(w);
	for (int i = 0; i < h; ++i)
	{
		int sum = 0;
		for (int j = 0; j < w; ++j)
		{
			cin>>f[i][j];
			sum += f[i][j];
		}
		row[i] = node(i, sum, w * x - sum);
	}

	for (int i = 0; i < w; ++i)
	{
		int sum = 0;
		for (int j = 0; j < h; ++j)
		{
			sum += f[j][i];
		}
		col[i] = node(i, sum, h * x - sum);
	}
	while (k--)
	{
		sort(row.begin(), row.end(), [](node& a, node& b)-> bool
		{
			return a.delta > b.delta;
		});
		sort(col.begin(), col.end(), [](node& a, node& b)-> bool
		{
			return a.delta > b.delta;
		});
		if (row[0].delta <= 0 && col[0].delta <= 0)
		{
			break;
		}
		if (row[0].delta > col[0].delta || (row[0].delta == col[0].delta && w > h))
		{
			row[0].res = x * w;
			row[0].delta = 0;
			for (int i = 0; i < w; ++i)
			{
				col[i].res = col[i].res - f[row[0].pos][col[i].pos] + x;
				col[i].delta = col[i].delta + f[row[0].pos][col[i].pos] - x;
				f[row[0].pos][i] = x;
			}
		}
		else
		{
			col[0].res = x * h;
			col[0].delta = 0;
			for (int i = 0; i < h; ++i)
			{
				row[i].res = row[i].res - f[row[i].pos][col[0].pos] + x;
				row[i].delta = row[i].delta + f[row[i].pos][col[0].pos] - x;
				f[i][col[0].pos] = x;
			}
		}
	}
	int myres = 0;
	for_each(row.begin(), row.end(), [&myres](node& x)
	{
		myres += x.res;
	});
		cout<<myres<<endl;
	return 0;
}