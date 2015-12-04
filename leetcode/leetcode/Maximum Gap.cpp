#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <unordered_map>
#include <sstream>
using namespace std;
class Solution {
public:
	int maximumGap(vector<int>& nums) {
		const int n = nums.size();
		auto p = minmax_element(nums.begin(), nums.end());
		int l = *p.first, h = *p.second;
		int gap = max((h - l) / (n - 1), 1);
		int m = (h - l) / gap + 1;
		vector<int> maxele(m, INT_MIN);
		vector<int> minele(m, INT_MAX);
		for (int i = 0; i < n; ++i)
		{
			int k = (nums[i] - l) / gap;
			maxele[k] = max(maxele[k], nums[i]);
			minele[k] = min(minele[k], nums[i]);
		}
		int res = maxele[0] - minele[0];
		int i = 0, j;
		while (i < m)
		{
			j = i + 1;
			while (j < m && maxele[j] == INT_MIN && minele[j] == INT_MAX)
			{
				++j;
			}
			if (j == m)
			{
				break;
			}
			res = max(res, minele[j] - maxele[i]);
			i = j;
		}
		return res;
	}
	int compareVersion(string version1, string version2) {
		auto a = version1.find('.');
		auto b = version2.find('.');
		int v1, v2, v3, v4;
		if (a == string::npos)
		{
			v1 = myatoi(version1);
			v2 = 0;
		}
		else
		{
			string v1a(version1.begin(), version1.begin() + a);
			string v1b(version1.begin() + a + 1, version1.end());
			v1 = myatoi(v1a);
			v2 = myatoi(v1b);

		}
		if (b == string::npos)
		{
			v3 = myatoi(version2);
			v4 = 0;
		}
		else
		{
			string v2a(version2.begin(), version2.begin() + b);
			string v2b(version2.begin() + b + 1, version2.end());
			v3 = myatoi(v2a);
			v4 = myatoi(v2b);
		}

		if (v1 != v3)
			return v1 < v3 ? -1 : 1;
		else if (v2 != v4)
			return v2 < v4 ? -1 : 1;
		return 0;

	}
	int myatoi(string& s)
	{
		stringstream os;
		os << s;
		int res;
		os >> res;
		return res;
	}
};
int main()
{
	Solution s;
	cout << s.compareVersion("0", "1") << endl;
	return 0;
}