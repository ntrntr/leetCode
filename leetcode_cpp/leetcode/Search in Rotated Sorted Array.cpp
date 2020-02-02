#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
class Solution {
public:
	int search(vector<int>& nums, int target) {
		/*auto it = find(nums.begin(), nums.end(), target);
		if (it == nums.end())
		{
			return -1;
		}
		else
		{
			return distance(it,nums.begin());
		}*/
		const int n = nums.size();
		int first = 0;
		int last = n;
		while(first != last)
		{
			int mid = (first + last) / 2;
			if (nums[mid] == target)
			{
				return mid;
			}
			if (nums[first] < nums[mid])
			{
				if (nums[first] <= target && target < nums[mid])
				{
					last = mid;
				}
				else
					first = mid + 1;
			}
			else
			{
				if (nums[mid] < target && target <= nums[last-1])
				{
					first = mid + 1;
				}
				else
					last = mid;
			}
		}
		return -1;
	}
};
int main()
{
	return 0;
}