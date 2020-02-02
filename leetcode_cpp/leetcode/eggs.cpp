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
const int n = 200, m = 200;
vector<vector<int>> dp;
int main()
{
	dp = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= m; ++i)
	{
		dp[1][i] = i;
	}
	for (int i = 2; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			dp[i][j] = 1 + dp[i][j - 1];
			for (int k = 2; k <= j; ++k)
			{
				dp[i][j] = min(dp[i][j], 1 + max(dp[i - 1][k - 1], dp[i][j - k]));
			}
		}
	}
	int a, b;
	while (cin>>a>>b)
	{
		cout << dp[a][b] << endl;
	}
	return 0;
}