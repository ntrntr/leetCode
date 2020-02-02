#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		vector<int> res(nums1);
		vector<int>::iterator it = res.end();
		for_each(nums2.begin(), nums2.end(), [&res](int x){res.push_back(x);});
		inplace_merge(res.begin(),res.begin() + nums1.size(), res.end() );
		return res.size() % 2 == 0 ?(0.5 * res[res.size() / 2] + 0.5 * res[res.size() / 2 - 1]):(res[res.size() / 2]);
	}
};
int main()
{
	vector<int> nums1(10);
	vector<int> nums2(10);
	int tmp = 1;
	for (auto &i:nums1)
	{
		i = tmp++;
	}
	tmp = 20;
	for (auto &i:nums2)
	{
		i = tmp++;
	}
	Solution s;
	cout<<s.findMedianSortedArrays(nums1, nums2)<<endl;
	return 0;
}