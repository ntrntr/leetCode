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
	bool isValid(string s) {
		vector<char> v;
		for(auto it = s.begin(); it != s.end(); ++it)
		{
			if(*it == '(' || *it == '{' || *it == '[')
			{
				v.push_back(*it);
			}
			else
			{
				if(v.size() == 0)
					return false;

				if(*it == ')' && v.back() == '(')
				{
					v.pop_back();
				}
				else if(*it == '}' && v.back() == '{')
				{
					v.pop_back();
				}
				else if(*it == ']' && v.back() == '[')
				{
					v.pop_back();
				}
				else
				{
					return false;
				}
			}
		}
		if (v.size() == 0)
		{
			return true;
		}
		else 
			return false;

	}
};
int main()
{
	Solution s;
	cout<<s.isValid("()")<<endl;
	return 0;
}