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
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> res;
		const int n = nums.size();
		unordered_map<int, int> myHash;
		int count = 1;
		for (auto i:nums)
		{
			myHash[i] = count++;
		}
		for(int i = 0; i < n - 1; ++i)
		{
			auto it= myHash.find(target - nums[i]);
			int tmp;
			if(it != myHash.end() && (tmp = it->second) != i + 1)
			{
				res.push_back(min(i + 1, tmp));
				res.push_back(max(i + 1, tmp));
				return res;
			}
		}
		return res;
	}
};
int main()
{
	return 0;
}