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
	double res = 1;
	double tmp;
	double maxData;
	int pos;
	vector<char> f{ 'W', 'T', 'L' };
	vector<int> g;
	for (int i = 0; i < 3; ++i)
	{
		pos = -1;
		maxData = INT_MIN;
		for (int j = 0; j < 3; ++j)
		{
			cin >> tmp;
			if (maxData < tmp)
			{
				maxData = tmp;
				pos = j;
			}
		}
		res *= maxData;
		g.push_back(pos);
	}
	for (int i = 0; i < 3; ++i)
	{
		if (i == 0)
		{
			cout << f[g[i]];
		}
		else
			cout << " " << f[g[i]];
	}
	printf(" %.2f\n", (res*0.65 - 1) * 2 + 0.005);
	return 0;
}