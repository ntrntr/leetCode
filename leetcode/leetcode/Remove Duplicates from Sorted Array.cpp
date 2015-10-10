#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		return distance(nums.begin(), unique(nums.begin(), nums.end(), [](int i, int j){return i == j;}));

	}
	int removeDuplicates2(vector<int>& nums) {
		const int n = nums.size();
		if (n <= 1)
		{
			return n;
		}
		vector<int> tmp;
		int prev = nums[0];
		tmp.push_back(prev);
		for (int i = 1; i < n; ++i)
		{
			if (nums[i] != prev)
			{
				prev = nums[i];
				tmp.push_back(prev);
			}
			else
			{

			}
		}
		nums = tmp;
		return tmp.size();
	}
	int removeDuplicates1(vector<int>& nums) {
		const int n = nums.size();
		if (n <= 1)
		{
			return n;
		}
		int res = 1;
		int prev = nums[0];
		auto it = nums.begin() + 1;
		while (it != nums.end())
		{
			if (*it != prev)
			{
				prev = *it;
				++res;
				++it;
			}
			else
			{
				prev = *it;
				it = nums.erase(it);
			}
		}
		return res;
	}
};
int main()
{
	return 0;
}