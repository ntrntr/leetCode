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
	string longestPalindrome(string s) {
		const int n = s.size();
		if(n <= 1)
			return s;
		int maxlen = 1;
		int begin = 0;
		int left; 
		int right;
		for (int i = 0; i < n; ++i)
		{
			left = i - 1;
			right = i + 1;
			while(left  >= 0 && right <= n - 1 && s[left] == s[right])
			{
				if (maxlen < right - left + 1)
				{
					maxlen = right - left + 1;
					begin = left;
				}
				left--;
				right++;
			}
			left = i;
			right = i + 1;
			while(left  >= 0 && right <= n - 1 && s[left] == s[right])
			{
				if (maxlen < right - left + 1)
				{
					maxlen = right - left + 1;
					begin = left;
				}
				left--;
				right++;
			}
		}

		return s.substr(begin, maxlen);
		
	}
	bool isPalindromic(int i, int j, string& s)
	{
		while(i < j)
		{
			if(s[i++] != s[j--])
			{
				return false;
			}
		}
		return true;
	}
};
int main()
{
	Solution s;
	cout<<s.longestPalindrome("bb");
	return 0;
}