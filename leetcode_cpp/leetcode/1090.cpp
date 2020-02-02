#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int maxPriceLen = 0;
int maxCount = 1;
void dfs(int cur, vector<int>& path, vector<int>& data)
{
	int father = data[cur];
	if (path[father] == -1)
	{
		dfs(father, path, data);
		path[cur] = path[father] + 1;
	}
	else
	{
		path[cur] = path[father] + 1;
	}
	if (maxPriceLen < path[cur])
	{
		maxPriceLen = path[cur];
		maxCount = 1;
	}
	else if (maxPriceLen == path[cur])
	{
		++maxCount;
	}
}
int main()
{
	int n;
	double p, r;
	cin>>n>>p>>r;
	vector<int> data(n);
	vector<int> path(n, -1);
	int tmp;
	for (int i = 0; i < n; ++i)
	{
		cin>>tmp;
		data[i] = tmp;
		if (tmp == -1)
		{
			path[i] = 0;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		if (path[i] == -1)
		{
			dfs(i, path, data);
		}
	}
	//cout<<p * pow( 1.0 + r * 1.0 / 100, maxPriceLen)<<" "<<maxCount<<endl;
	printf("%.2lf %d\n",p * pow( 1.0 + r * 1.0 / 100, maxPriceLen), maxCount);
	return 0;
}