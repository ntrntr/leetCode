#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int> num(n);
	vector<int> left(n, 0);
	vector<int> right(n, 2147483647);
	vector<int> res;
	for (int i = 0; i < n; ++i)
	{
		cin>>num[i];
		if (i == 0)
		{
			left[i] = num[i];
		}
		else
		{
			left[i] = max(left[i - 1], num[i]);
		}

	}
	for (int i = n - 1; i >= 0; --i)
	{
		if (i == n-1)
		{
			right[i] = num[i];
		}
		else
		{
			right[i] = min(right[i + 1], num[i]);
		}
	}
	for (int i = 0; i < n; ++i)
	{
		if (left[i] == right[i])
		{
			res.push_back(num[i]);
		}
	}
	sort(res.begin(), res.end());
	int size = res.size();
	cout<<size<<endl;
	for (int i = 0; i < size; ++i)
	{
		if (i == 0)
		{
			cout<<res[i];
		}
		else
		cout<<" "<<res[i];
	}
	cout<<endl;
	return 0;
}