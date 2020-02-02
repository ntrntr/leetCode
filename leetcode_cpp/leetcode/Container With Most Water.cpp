#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
class Solution {
public:
	int maxArea(vector<int>& height) {
		int res = 0;
		const int n = height.size();
		int start = 0,end = n - 1;
		while(start<end)
		{
			res = max(res, (end - start) * min(height[start], height[end]));
			if(height[start] <= height[end])
				start++;
			else
				end--;
		}
		return res;
	}
};
int main()
{
	Solution s;
	int a[] = {2, 1};
	vector<int> f;
	for (int i = 0; i < 2; ++i)
	{
		f.push_back(a[i]);
	}
	cout<<s.maxArea(f)<<endl;
	return 0;
}