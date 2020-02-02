#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <unordered_map>
#include <functional>
#include <deque>
using namespace std;
//class Solution {
//public:
//	void wiggleSort(vector<int>& nums) {
//		const int n = nums.size();
//		if (n <= 1)
//			return;
//		sort(nums.begin(), nums.end());
//		int curpos = 3;
//		//for (int i = 1; i < n-1;)
//		/*{
//			if (nums[i - 1] == nums[i])
//			{
//				tmp = nums[i];
//				auto pos = find_if(nums.begin() + i + 1, nums.end(), [&tmp](int& a)
//				{
//					return a > tmp;
//				});
//				swap(*pos, nums[i + 1]);
//				i += 2;
//			}
//			else
//			{
//				tmp = nums[i + 1];
//				auto pos = find_if(nums.begin() + i + 2, nums.end(), [&tmp](int& a)
//				{
//					return a > tmp;
//				});
//				swap(*pos, nums[i + 1]);
//
//			}
//		}*/
//	}
//	int coinChange(vector<int>& coins, int amount) {
//		sort(coins.begin(), coins.end(), greater<int>());
//		result = -1;
//		int count = 0;
//		dfs(0, coins, amount, count);
//		return result;
//	}
//	void dfs(int pos, vector<int>& coins, int amount, int count)
//	{
//		if (pos == coins.size() || amount == 0)
//		{
//			if (amount == 0)
//			{
//				result = min(count, result);
//			}
//			return;
//		}
//		//chu
//		dfs(pos + 1, coins, amount % coins[pos], count + amount % coins[pos]);
//		//buchu
//		dfs(pos + 1, coins, amount, count);
//	}
//	int result;
//};
class MedianFinder {
public:

	// Adds a number into the data structure.
	void addNum(int num) {
		auto pos = lower_bound(data.begin(), data.end(), num);
		data.insert(pos, num);
	}

	// Returns the median of current data stream
	double findMedian() {
		int n = data.size();
		int mid = n / 2;
		if (n % 2 == 0)
			return (data[mid] + data[mid - 1]) / 2.0;
		else
			return data[mid];
	}
	deque<int> data;
};
int main()
{
	//Solution s;
	vector<int> f{ 186, 419, 83, 408};
	//cout << s.coinChange(f, 6249) << endl;
	return 0;
}