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
	vector<long int> f(n + 1, 0);
	vector<long int> g(n + 1, 0);
	f[1] = 1;
	g[1] = 1;
	long int maxlen = 0;
	long int pos = 0;
	for (long int i = 2; i <= n; ++i)
	{
		long int count = 0;
		for (long int j = 2; j < i; ++j)
		{
			if (i % j == 0)
			{
				count++;
			}
		}
		g[i] = 2 + count;
		if (maxlen < g[i])
		{
			maxlen = g[i];
			pos = i;
		}
	}
	
	/*int count = 0;
	for (auto i:g)
	{
		cout << count++ << ": " << i << endl;
	}*/
	//cout << maxlen << endl;
	cout << pos << endl;
	return 0;
}