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
	vector<int> g;
	map<int, int> f;
	int tmp = 0;
	for (int i = 0; i < n; ++i)
	{

		cin >> tmp;
		g.push_back(tmp);
		f[tmp]++;
	}
	for (int i = 0; i < n; ++i)
	{
		if (f[g[i]] == 1)
		{
			cout << g[i] << endl;
			return 0;
		}
	}
	cout << "None" << endl;

	return 0;
}