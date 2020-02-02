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
vector<vector<int>> myres;
vector<int> f;
vector<int> choosed;
int n, m;
int sum = 0;
int hasfind = 0;
void dfs(int pos, vector<int>&f, vector<int>&path, int sum)
{

	if (sum == 0)
	{
		myres.push_back(path);
		return;
	}
	if (sum < 0 || pos >= f.size())
	{
		return;
	}
	path.push_back(f[pos]);
	dfs(pos + 1, f, path, sum - f[pos]);
	path.pop_back();
	dfs(pos + 1, f, path, sum);
}
void findResult(int x)
{
	for (int i = x; i < m; ++i)
	{
		choosed[i] = 1;
		sum += f[i];
		if (sum < m)
		{
			findResult(i + 1);
		}
		else if (sum == m)
		{
			hasfind = 1;
			return;
		}
		else
		{
			sum -= f[i];
			choosed[i] = 0;
			break;
		}
		if (hasfind)
		{
			break;
		}
		sum -= f[i];
		choosed[i] = 0;
	}

}
int main()
{
	
	cin >> n >> m;
	f = vector<int>(n, 0);
	choosed = vector<int>(n, 0);
	for (int i = 0; i < n;++i)
	{
		cin >> f[i];
	}
	sort(f.begin(), f.end());
	findResult(0);
	int flag = 1;
	if (!hasfind)
	{
		cout << "No Solution" << endl;
		return 0;
	}
	for (size_t i = 0; i < choosed.size(); i++)
	{
		if (choosed[i])
		{
			if (flag)
			{
				flag = 0;
			}
			else
			{
				cout << " ";
			}
			cout << f[i];
		}
	}
	cout << endl;
	
	return 0;
}