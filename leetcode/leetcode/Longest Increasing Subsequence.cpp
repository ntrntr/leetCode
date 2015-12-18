#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <unordered_map>
using namespace std;
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		const int n = nums.size();
		if (n <= 1)
		{
			return n;
		}
		vector<int> f(n, 1);
		f[0] = 1;
		int prevMax = 1;
		for (int i = 1; i < n; ++i)
		{
			for (int j = i - 1; j >= 0; --j)
			{
				if (nums[i] > nums[j])
				{
					f[i] = max(f[i],f[j] + 1);
					prevMax = max(prevMax, f[i]);
				}
			}
		}
		return prevMax;
	}
};
int main()
{
	Solution s;
	vector<int> f{ 3, 5, 6, 2, 5, 4, 19, 5, 6, 7, 12 };
	cout << s.lengthOfLIS(f) << endl;
	return 0;
}