#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <unordered_map>
#include <limits.h>
#include <math.h>
using namespace std;
void getRes(int n)
{
	int min_start = n;
	int max = 1;
	int sqrtn = sqrt(n);
	int i = 2;
	for (; i < sqrtn; ++i)
	{
		if (n % i == 0)
		{
			int len = 1;
			int tmpn = n/i;
			while (tmpn%(++i) == 0)
			{
				++len;
				tmpn /= i;
			}
			if (len > max)
			{
				max = len;
				i = i - len;
				min_start = i;
			}
			else if (len == max && i < min_start)
			{
				i = i - len;
				min_start = i;
			}
		}
	}
	cout << max << endl;
	for (int i = 0; i < max; ++i)
	{
		if (i == max - 1)
		{
			cout << min_start << endl;
		}
		else
			cout << min_start++ << "*";
	}
	
}
int main()
{
	int n;
	cin >> n;
	getRes(n);
	return 0;
}