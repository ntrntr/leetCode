#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string res = "";
		const int size = strs.size();
		if(size == 0)
			return res;
		if(size == 1)
		{
			return strs[0];
		}
		int pos = 0;
		int flag = 1;
		while(flag)
		{
			if(pos + 1 > strs[0].size())
			{
				flag = 0;
				break;
			}
			char tmp = strs[0][pos];
			for(int i = 1; i < size; ++i)
			{
				if(pos + 1 > strs[i].size()|| tmp != strs[i][pos])
				{
					flag = 0;
					break;
				}
			}
			++pos;
			if(flag)
			{
				res += tmp;
			}

		}

		return res;

	}
};
int main()
{
	Solution s;
	vector<string> ss;
	ss.push_back("");
	ss.push_back("");
	cout<<s.longestCommonPrefix(ss)<<endl;
	return 0;
}