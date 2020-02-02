#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <unordered_map>
#include <limits.h>
using namespace std;
#define P(a,b) pair<int, int>(a,b)
class Solution {
public:
	int maxEnvelopes(vector<pair<int, int>>& envelopes) {
		if (envelopes.size() <= 1)
		{
			return envelopes.size();
		}
		sort(envelopes.begin(), envelopes.end(), [](const pair<int, int>& a, const pair<int, int>& b)
		{
			if (a.first == b.first)
			{
				return a.second > b.second;
			}
			else
			{
				return a.first < b.first;
			}
		});
		vector<int> tmp;
		for (int i = 0; i < envelopes.size(); ++i)
		{
				tmp.push_back(envelopes[i].second);
		}
		return lengthOfLIS(tmp) ;

	}
	int lcs(vector<int>& l1, vector<int>& l2)
	{
		int len1 = l1.size(), len2 = l2.size();
		vector<vector<int>> length(len1, vector<int>(len2, 0));
		for (int i = 0; i < len1; ++i)
		{
			for (int j = 0; j < len2; ++j)
			{
				if (i == 0 || j == 0)
				{
					if (l1[i] == l1[j])
					{
						length[i][j] = 1;
					}
					else
						length[i][j] = 0;
				}
				else if (l1[i] == l2[j])
				{
					length[i][j] = length[i - 1][j - 1] + 1;
				}
				else if (length[i - 1][j] > length[i][j - 1])
				{
					length[i][j] = length[i - 1][j];
				}
				else
				{
					length[i][j] = length[i][j - 1];
				}
			}
		}
		return length[len1][len2];
	}
	int upper_bound(int arr[], int s, int e, int key)
	{
		int mid;
		if (arr[e] <= key)
			return e + 1;
		while (s < e)
		{
			mid = s + (e - s) / 2;
			if (arr[mid] <= key)
				s = mid + 1;
			else
				e = mid;
		}
		return s;
	}
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
					f[i] = max(f[i], f[j] + 1);
					prevMax = max(prevMax, f[i]);
				}
			}
		}
		return prevMax;
	}
	int LIS1(int d[], int n)
	{
		int i = 0, len = 1, *end = (int *)alloca(sizeof(int)* (n + 1));
		end[1] = d[0]; //初始化：长度为1的LIS末尾为d[0]
		for (i = 1; i < n; i++)
		{
			int pos = upper_bound(end, 1, len, d[i]); //找到插入位置
			end[pos] = d[i];
			if (len < pos) //按需要更新LIS长度
				len = pos;
		}
		return len;
	}
	int LIS_DP_N2(int *array, int nLength)
	{

		int *LIS = new int[nLength];
		for (int i = 0; i < nLength; i++)
		{
			LIS[i] = 1;
		}

		for (int i = 1; i < nLength; i++)
		{
			int maxLen = 0;
			for (int j = 0; j < i; j++)
			{
				if (array[i] > array[j])
				{
					if (maxLen < LIS[j])
						maxLen = LIS[j];
				}
			}
			LIS[i] = maxLen + 1;
		}
		int maxLIS = 0;
		for (int i = 0; i < nLength; i++)
		{
			if (maxLIS < LIS[i])
				maxLIS = LIS[i];
		}

		return maxLIS;
	
	}
};
int main()
{
	Solution s;
	//[[5, 4], [6, 4], [6, 7], [2, 3]]
	vector<pair<int, int>> d{ P(30, 50), P(12, 2), P(3, 4), P(12, 15) };
	
	cout << s.maxEnvelopes(d) << endl;
	return 0;
}