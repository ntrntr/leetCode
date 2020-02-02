#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		vector<int> sorted(nums);
		sort(sorted.begin(), sorted.end());
		for (int i = nums.size() - 1, j = 0, k = i / 2 + 1; i >= 0; --i)
			nums[i] = sorted[(i & 1) ? k++ : j++];
	}
};
//int main()
//{
//	vector<int> nums{ 1, 2, 3, 4, 5, 6, 7 };
//	Solution s;
//	s.wiggleSort(nums);
//	for (auto i:nums)
//	{
//		cout << i << " ";
//	}
//	return 0;
//}