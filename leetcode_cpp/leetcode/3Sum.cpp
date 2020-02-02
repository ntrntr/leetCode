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
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		const int n = nums.size();
		if (n < 3)
		{
			return res;
		}
		sort(nums.begin(), nums.end());
		auto last = nums.end();
		const int target = 0;
		vector<int> tmp(3);
		for (auto a = nums.begin(); a < prev(last, 2); ++a)
		{
			if (a > nums.begin() && (*a) == (*(a-1)))
			{
				continue;
			}
			auto b = next(a, 1);
			auto c = prev(last, 1);
			while (b < c)
			{
				if (b > (a + 1) && (*b) == (*(b-1)))
				{
					++b;
					continue;
				}
				if (c < prev(last, 1) && (*c) == (*(c + 1)))
				{
					--c;
					continue;
				}
				if (*a + *b + *c < target)
				{
					++b;
				}
				else if (*a + *b + *c > target)
				{
					--c;
				}
				else
				{
					
					tmp[0] = *a;
					tmp[1] = *b;
					tmp[2] = *c;
					res.push_back(tmp);
					++b;
					--c;
				}
			}
		}
		sort(res.begin(), res.end());
		res.erase(unique(res.begin(), res.end()), res.end());
		return res;
	}
};
int main()
{
	Solution s;
	int a[] = {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
	vector<int> tmp(a, a + 110);
	for (auto i:s.threeSum(tmp))
	{
		for (auto j:i)
		{
			cout<<j<<" ";
		}
		cout<<endl;
	}
	return 0;
}