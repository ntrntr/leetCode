#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <stack>
#include <sstream>
using namespace std;
class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> stk;
		int tmp;
		string s[]={"+","-","*","/"};
		vector<string> f(s, s + 4);
		for (int i = 0; i < tokens.size(); ++i)
		{
			auto it  = find_if(f.begin(), f.end(), [&tokens, i](string s)
			{
				return s == tokens[i];
			});
			if (it != f.end())
			{
				int flag = distance(f.begin(), it);
				tmp = stk.top();
				stk.pop();
				if (flag == 0)
				{
					tmp += stk.top();
				}
				else if (flag == 1)
				{
					tmp = stk.top() - tmp;
				}
				else if (flag == 2)
				{
					tmp *= stk.top();
				}
				else if (flag == 3)
				{
					tmp = stk.top() / tmp;
				}
				stk.pop();
				stk.push(tmp);
			}
			else
			{
				int tmp;
				stringstream os;
				os<<tokens[i];
				os>>tmp;
				stk.push(tmp);
			}
		}
		return stk.top();
	}
};
int main()
{
	Solution s;
	string a[] = {"4", "13", "5", "/", "+"};
	vector<string> f(a, a + 5);
	cout<<s.evalRPN(f)<<endl;
	return 0;
}