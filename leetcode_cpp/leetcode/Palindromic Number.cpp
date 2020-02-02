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
bool isPalindromic(vector<int>& f)
{
	int i = 0, j = f.size() - 1;
	while (i < j)
	{
		if (f[i++] != f[j--])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	long int n;
	int k;
	cin >> n >> k;
	vector<int> f;
	vector<int> g;
	vector<int> res;
	do 
	{
		f.push_back(n % 10);
		n = n / 10;
	} while (n);
	int count = 0;
	while (count < k)
	{
		if (isPalindromic(f))
		{
			for (auto i:f)
			{
				cout << i;
			}
			cout << endl << count << endl;
			return 0;
		}
		else
		{
			g.assign(f.rbegin(), f.rend());
			int jinwei = 0;
			int tmp = 0;
			for (int i = 0; i < f.size(); ++i)
			{
				tmp = (f[i] + g[i] + jinwei);
				f[i] =  tmp % 10;
				jinwei = tmp / 10;
			}
			if (jinwei > 0)
			{
				f.push_back(jinwei);
			}
		}
		count++;
	}
	//reverse(f.begin(), f.end());
	for (int i = f.size() - 1; i >= 0; --i)
	{
		printf("%d", f[i]);
		//cout << f[i];
	}
	cout << endl << count << endl;
	return 0;
}