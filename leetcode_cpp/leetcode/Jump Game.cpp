#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
//class Solution {
//public:
//	bool canJump(vector<int>& nums) {
//		const int n = nums.size();
//		vector<int> f(n, 0);
//		f[n-1] = 1;
//
//		for(int i = n - 2; i >=0; --i)
//		{
//			for(int j = 1; j <= nums[i]; ++j)
//			{
//				if(f[i + j] == 1)
//				{
//					f[i] = 1;
//					break;
//				}
//			}
//		}
//		return f[0];
//	}
//};
//class Solution {
//public:
//	int jump(vector<int>& nums) {
//		const int n = nums.size();
//		vector<int> f(n, INT_MAX);
//		f[0] = 0;
//		for(int i = 0; i < n; ++i)
//		{
//			for(int j = 1; j <= nums[i] && i + j <n; ++j)
//			{
//				f[i + j] = min(f[i+j], f[i] + 1);
//			}
//		}
//
//		return f[n-1];
//	}
//};
//class Solution {
//public:
//	int maxProfit(vector<int>& prices) {
//		const int n = prices.size();
//		if(n == 0)
//			return 0;
//		vector<int> left(n, INT_MAX);
//		vector<int> right(n, INT_MIN);
//		int res = 0;
//		int temp = prices[0];
//		left[0] = 0; 
//		for(int i = 1; i < n; ++i)
//		{
//			temp = min(temp, prices[i]);
//			left[i] = max(left[i - 1], prices[i] - temp);
//		}
//		temp = prices[n - 1];
//		right[n - 1] = 0;
//		for(int i = n - 2; i >= 0; --i)
//		{
//			temp = max(temp, prices[i]);
//			right[i] = max(right[i + 1], temp - prices[i]);
//		}
//		for(int i = 0; i < n; ++i)
//		{
//			res = max(res, (left[i] + right[i]));
//		}
//		return res;
//	}
//};
class Solution {
public:
	int flag;
	int maxProfit(int k, vector<int>& prices) {
		int res = 0;
		const int n = prices.size();
		vector<vector<int> > f(n, vector<int>(n, 0));
		int tmp;
		for (int i = 0; i < n; ++i)
		{
			tmp = prices[i];
			for (int j = i; j < n; ++j)
			{
				tmp = min(tmp, prices[j]);
				if (i == j)
				{
					continue;
				}
				f[i][j] = max(f[i][j-1], prices[j] - tmp);
			}
		}
		flag  = 1;
		dfs(1, 0, 0, k, f, res);
		return res;
	}
	void dfs(int cur, int pre, int sum, int k, vector<vector<int> >& f, int& res)
	{
		
		if (pre == f.size() - 1 || k == 0)
		{
			res = max(res, sum);
			return;
		}
		if (cur >= f.size() || k <= 0)
		{
			return;
		}
		
		
		//add
		if (flag)
		{
			dfs(cur + 1, cur, sum + f[pre][cur], k - 1, f, res);
		}
		if (flag)
		{
			dfs(cur + 1, pre, sum, k, f, res);
		}
		//next
		
		

		
		
	}
};
//class Solution {
//public:
//	int cmp(int& x, int& y)
//	{
//		return x > y;
//	}
//	int maxProfit(int k, vector<int>& prices) {
//		int res = 0;
//		const int n = prices.size();
//		int prev = prices[0];
//		vector<int> path;
//		
//		for(int i = 1; i < n; ++i)
//		{
//			if(prices[i] - prev > 0)
//			{
//				path.push_back(prices[i] - prev);
//
//			}
//
//			prev = prices[i];
//		}
//		sort(path.begin(), path.end());
//		reverse(path.begin(), path.end());
//		for (auto i:path)
//		{
//			cout<<i<<" ";
//		}
//		cout<<endl;
//		for (int i = 0; i < k && i < path.size(); ++i)
//		{
//			cout<<path[i]<<" ";
//			res += path[i];
//		}
//		cout<<endl;
//		return res;
//	}
//
//};
int main()
{
	Solution s;
	int a[30] = {48,12,60,93,97,42,25,64,17,56,85,93,9,48,52,42,58,85,81,84,69,36,1,54,23,15,72,15,11,94};
	vector<int> f(a, a + 30);
	cout<<s.maxProfit(11, f)<<endl;
	//cout<<s.maxProfit(f)<<endl;
	return 0;
}