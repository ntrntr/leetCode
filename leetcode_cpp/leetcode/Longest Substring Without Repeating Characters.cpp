#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		vector<int> f(260,0);
		vector<int> pos(260, 0);
		string tmp;
		int res = 0;
		int i = 0,j = 0;
		while (j != s.size())
		{
			int tmp = s[j];
			if ((++f[tmp]) == 1)
			{
				pos[tmp] = j;
				if (j == s.size() - 1)
				{
					res = max(res, j - i + 1);
				}
				++j;
			}
			else
			{
				
				for (int k = i; k <= pos[tmp]; ++k)
				{
					--f[s[k]];
				}
				
				res = max(res, j - i);
				i = pos[tmp] + 1;
				pos[tmp] = j;
				
				++j;
			}

		}
		
		return res;
	}
};
int main()
{
	Solution s;
	cout<<s.lengthOfLongestSubstring("abcdabcabcd")<<endl;
	return 0;
}