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
	bool isScramble(string s1, string s2) {
		string::iterator it = find(s2.begin(), s2.end(), *s1.begin());
		if(it  == s2.end())
			return false;
		int dis = distance(s2.begin(), it);
		string::iterator s1mid  = s1.begin() + dis + 1;
		string::iterator s2mid = s2.begin() + dis + 1;
		return isscramble(begin(s1), s1mid , begin(s2), s2mid) && isscramble(s1mid, end(s1), s2mid, end(s2));
	}
	bool isscramble(string::iterator start1,string::iterator end1,string::iterator start2,string::iterator end2)
	{
		if(start1 == end1)
			return true;
		auto it = find(start2, end2, *start1);
		if(it  == end2)
			return false;
		if(it == prev(end2))
		{
			reverse(start2,end2);
			while (start1 != end1)
			{
				if (*start1++ != *start2++)
				{
					return false;
				}
			}
			return true;
		}
		else
		{
			int dis = distance(start2, it);
			string::iterator s1mid  = start1 + dis + 1;
			string::iterator s2mid = start2 + dis + 1;
			return isscramble(start1, s1mid , start2, s2mid) && isscramble(s1mid, end1, s2mid, end2);
		}
		return true;
	}
};
int main()
{
	Solution s;
	cout<<s.isScramble("abc", "bca")<<endl;
	return 0;
}