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
	int threeSumClosest(vector<int>& nums, int target) {
		const int n = nums.size();
		long int res = INT_MAX;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < n - 2; ++i)
		{
			int j = i + 1;
			int k = n - 1;
			while (j < k)
			{
				int tmp = getSum(i, j, k, nums);
				res = abs(tmp - target) < abs(res - target) ? tmp:res;
				if (tmp == target)
				{
					return target;
				}
				if (tmp < target)
				{
					++j;
				}
				else if (tmp > target)
				{
					--k;
				}

			}
		}
		return res;
	}
	int getSum(int a, int b, int c, vector<int>& nums)
	{
		return nums[a] + nums[b] + nums[c];
	}
};
int main()
{
	Solution ss;
	int s[] = {0,1,1,1};
	vector<int> nums(s, s + 4);
	cout<< ss.threeSumClosest(nums, 100)<<endl;
	return 0;
}