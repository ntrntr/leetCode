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
	int longestValidParentheses(string s) {
		stack<int> stk;
		int last = -1;
		int maxlen = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == '(')
			{
				stk.push(i);
			}
			else
			{
				if (stk.empty())
				{
					last = i;
				}
				else
				{
					stk.pop();
					if (stk.empty())
					{
						maxlen = max(maxlen, i - last);
					}
					else
					{
						maxlen = max(maxlen, i - stk.top());
					}
				}
			}
		}
		return maxlen;
	}
};
class Solution1 {
public:
	int longestValidParentheses(string s) {
		int max_len = 0, last = -1; // the position of the last ')'
		stack<int> lefts; // keep track of the positions of non-matching '('s
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] =='(') {
				lefts.push(i);
			} else
			{
				if (lefts.empty()) {
					// no matching left
					last = i;
				} else 
				{
					// find a matching pair
					lefts.pop();
					if (lefts.empty())
					{
						max_len = max(max_len, i-last);
					} else {
						max_len = max(max_len, i-lefts.top());
					}
				}
			}
		}
		return max_len;
	}
};
int main()
{
	Solution s;
	cout<<s.longestValidParentheses("()(()")<<endl;
	return 0;
}