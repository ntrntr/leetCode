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
vector<int> res;
bool isPalindromic(int n, int base)
{
	do 
	{
		res.push_back(n % base);
		n = n / base;
	} while (n);
	int start = 0, end = res.size() - 1;
	while (start < end)
	{
		if (res[start++] != res[end--])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int n, base;
	cin >> n >> base;
	if (isPalindromic(n,base))
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	for (int i = 0; i < res.size(); ++i)
	{
		if (i == 0)
		{
			cout << res[res.size() - i - 1];
		}
		else
			cout << " " << res[res.size() - i - 1];
	}
	cout << endl;
	return 0;
}