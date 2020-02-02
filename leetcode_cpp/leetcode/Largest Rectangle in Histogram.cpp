#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <stack>
using namespace std;
class Solution {
public:
	int largestRectangleArea(vector<int>& height) {
		//const int n = height.size();
		//int res = 0;
		//for (int i = 0; i < n; ++i)
		//{
		//	res = max(res, getMax(i, height));
		//}
		//return res;
		stack<int> stk;
		height.push_back(0);
		int res = 0;
		for (int i = 0; i < height.size();)
		{
			if (stk.empty() || height[i] > height[stk.top()])
			{
				stk.push(i++);
			}
			else
			{
				int tmp = stk.top();
				stk.pop();
				res = max(res, height[tmp] * (stk.empty() ? i : i - stk.top() - 1));
			}
		}
		return res;
	}
	int getMax(int cur, vector<int>& height)
	{
		int res = height[cur];
		int len = height[cur];
		for (int i = cur - 1; i > 0; --i)
		{
			if (height[i] >= len)
			{
				res = max(res, (cur - i + 1) * len);
			}
			else if (height[i] < len)
			{
				len = height[i];
				res = max(res, (cur - i + 1) * len);
			}
		}
		return res;
	}
};
int main()
{
	Solution s;
	int a[] = {2,1,5,6,2,3};
	vector<int> f(a, a + 6);
	cout<<s.largestRectangleArea(f)<<endl;
	return 0;
}