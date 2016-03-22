#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<long int> mypow;
int myend;
int maxSum = 0;
void dfs(long int n, int k, int p, vector<int>& path, vector<int> & res,int cur, int curSum)
{
	if (k == 0)
	{
		if (n == 0)
		{
			if (curSum >= maxSum)
			{
				maxSum = curSum;
				res = path;
			}
			
		}
		return;
	}
	for (int i = cur; i <= 20; ++i)
	{
		long int tmp = n - mypow[i];
		if (tmp >= 0)
		{
			path.push_back(i);
			dfs(tmp, k - 1, p, path, res, i, curSum + i);
			path.pop_back();
		}
		else
		{
			return;
		}
	}
}
int main()
{
	int n, k, p;
	cin >> n >> k >> p;
	//n = 169;
	//k = 5;
	//p = 2;
	mypow.resize(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		mypow[i] = (long int) pow(i,p);
		if (mypow[i - 1] > n)
		{
			myend = i;
			break;
		}
	}
	vector<int> res;
	vector<int> path;
	if (k == 0 || n < 0)
	{
		cout << "Impossible" << endl;
	}
	dfs(n, k, p, path, res, 1, 0);
	if (res.size() == 0)
	{
		cout << "Impossible" << endl;

	}
	else
	{
		
		reverse(res.begin(), res.end());
		cout << n << " = ";
		for (int i = 0; i < k; ++i)
		{
			if (i == 0)
			{
				cout << res[i] << "^" << p;
			}
			else
			{
				cout << " + " << res[i] << "^" << p;
			}
		}
	}

	return 0;
}