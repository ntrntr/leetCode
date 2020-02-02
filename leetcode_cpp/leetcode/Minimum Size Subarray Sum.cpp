#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <unordered_map>
#include <limits.h>
#include <numeric>
using namespace std;
class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int res = accumulate(nums.begin(), nums.end(), 0);
		if (res < s)
		{
			return 0;
		}
		res = 0;
		int n = nums.size();
		int p = 0, q = 1;
		int cursum = nums[0];
		int minlen = INT_MAX;
		int minSum = INT_MAX;
		int len = 1;
		while (q < n || cursum >= s)
		{
			if (cursum >= s && cursum <= minSum && len < minlen)
			{
				minlen = len;
				minSum = cursum;
			}
			if (cursum < s)
			{
				cursum += nums[q];
				len++;
				q++;
			}
			else if (cursum >= s)
			{
				cursum -= nums[p];
				len--;
				p++;
			}
			if (cursum >= s && cursum <= minSum && len < minlen)
			{
				minlen = len;
				minSum = cursum;
			}
		}
		return minlen;
	}
};
int main()
{
	Solution s;
	vector<int> test{ 1, 2,3,4,5};
	cout << s.minSubArrayLen(11, test) << endl;
	return 0;
}