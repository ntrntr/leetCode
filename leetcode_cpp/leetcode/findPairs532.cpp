#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
	int findPairs(vector<int>& nums, int k) {
		map<int, vector<int> > dct;
		auto nums_len = nums.size();
		for (int i=0; i < nums_len; i++)
		{
			auto val = nums[i];
			if(dct.find(val) == dct.end())
			{
				dct[val] = vector<int>{ i };
			}
			else
			{
				dct[val].push_back(i);
			}
		}
		auto ret = 0;
		map<pair<int, int>, int> check_dct;
		for(auto it=dct.begin(); it != dct.end(); ++it)
		{
			auto cur = it->first;
			auto cur_index = it->second.front();
			
			auto ls = vector<int>{ cur + k, cur - k };
			if (k == 0)
			{
				ls.pop_back();
			}
			for(auto next_val:ls)
			{
				if(dct.find(next_val) != dct.end() && dct[next_val].back() > cur_index && check_dct.find(make_pair(min(cur, next_val), max(cur, next_val))) == check_dct.end())
				{
					ret += 1;
					// cout << cur << "\t" << next_val << endl;
					check_dct[make_pair(min(cur, next_val), max(cur, next_val))] = 1;
				}
			}
		}
		return ret;

	}
};

int main(void)
{
	auto s = Solution();
	cout << s.findPairs(vector<int>{3, 1, 4, 1, 5 }, 2) << endl;
	cout << s.findPairs(vector<int>{1, 2, 3, 4, 5 }, 1) << endl;
	cout << s.findPairs(vector<int>{1, 3, 1, 5, 4 }, 0) << endl;
	cout << s.findPairs(vector<int>{1, 2, 4, 4, 3, 3, 0, 9, 2, 3 }, 3) << endl;
	cout << s.findPairs(vector<int>{-1, -2, -3 }, 1) << endl;
	return 0;
}