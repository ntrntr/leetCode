#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;
class Solution {
public:
	int candy(vector<int>& ratings) {
		const int n = ratings.size();
		vector<int> f(n, 0);
		
		for (int i = 1, inc = 1; i < n; ++i)
		{
			if (ratings[i] > ratings[i - 1])
			{
				f[i] = max(inc++, f[i]);
			}
			else
			{
				inc = 1;
			}
		}

		for (int i = n - 2, inc  = 1;i >= 0; i-- )
		{
			if (ratings[i] > ratings[i + 1])
			{
				f[i] = max(inc++, f[i]);
			}
			else
			{
				inc = 1;
			}
		}

		//for (int i = 1; i < n; ++i)
		//{
		//	fuc(i, f, ratings);
		//}
		int sum = 0;
		for_each(f.begin(), f.end(), [&sum](const int x)
			{
				sum += x;
			});
		//
		return sum;
	}
	void fuc(int x, vector<int>& f, vector<int>& ratings)
	{
		if (x == 0)
		{
			return;
		}
		if (ratings[x - 1] > ratings[x])
		{
			if (f[x - 1] <= f[x])
			{
				f[x - 1] = f[x] + 1;
				fuc(x - 1, f, ratings);
			}
		}
		else if (ratings[x - 1] < ratings[x])
		{
			if (f[x - 1] >= f[x])
			{
				f[x] = f[x - 1] + 1;
			}
		}
	}
};
int main()
{
	return 0;
}