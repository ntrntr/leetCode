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
	int trap(vector<int>& height) {
		const int n = height.size();
		vector<int> right_max(n, 0);
		vector<int> left_max(n, 0);
		int res = 0;
		for (int i = 1; i < n; ++i)
		{
			left_max[i] = max(left_max[i - 1], height[i - 1]);
			right_max[n - i - 1] = max(right_max[n - i], height[n - i]);
		}
		int sum = 0;
		for ( int i = 0; i < n; ++i)
		{
			int tmp = min(left_max[i], right_max[i]);
			
			res += (tmp > height[i]) ? tmp - height[i] : 0;
		}
		return res;
	}
	int trap1(vector<int>& height) {
		vector<int> tmp(height);
		auto pivot = tmp.begin();
		while (pivot != tmp.end())
		{
			int data = *pivot;
			auto it = find_if(pivot + 1, tmp.end(), [&data](int x) -> bool{ return x>=data;});
			if (it == tmp.end())
			{
				++pivot;
				continue;
			}
			if (distance(pivot, it) <= 1)
			{
				pivot = it;
				continue;
			}
			for_each(pivot, it, [data](int& x){ x = data;});
			pivot = it;
			
		}
		//reverse(tmp.begin(), tmp.end());
		vector<int> tmp1(tmp.rbegin(), tmp.rend());
		tmp = tmp1;
		pivot = tmp.begin();
		while (pivot != tmp.end())
		{
			int data = *pivot;
			auto it = find_if(pivot + 1, tmp.end(), [&data](int x) -> bool{ return x>=data;});
			if (it == tmp.end())
			{
				++pivot;
				continue;
			}
			if (distance(pivot, it) <= 1)
			{
				pivot = it;
				continue;
			}
			for_each(pivot, it, [data](int& x){ x = data;});
			pivot = it;

		}

		int a = 0,b = 0;
		for_each(height.begin(),height.end(),[&a](int x){ a += x;});
		for_each(tmp.begin(),tmp.end(),[&b](int x){ b += x;});
		return b-a;
	}
};
int main()
{
	Solution s;
	int a[] = {4,2,3};
	vector<int> f(a, a + 3);
	cout<<s.trap(f)<<endl;
	return 0;
}