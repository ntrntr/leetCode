#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <sstream>
using namespace std;
class Solution {
public:
	string countAndSay(int n) {
		/*vector<char> res(1,'1');
		vector<char> tmp;
		n = n - 1;
		while (n--)
		{
		char pre = res[0];
		int count = 1;
		for (int i = 1; i < res.size(); ++i)
		{
		if (pre == res[i])
		{
		count++;
		}
		else
		{
		tmp.push_back(('0' + count));
		tmp.push_back(pre);
		pre = res[i];
		count = 1;
		}
		}
		tmp.push_back(('0' + count));
		tmp.push_back(pre);
		res = tmp;
		tmp.clear();
		}
		string r(res.begin(), res.end());
		return r;*/
		string s("1");
		while (--n)
		{
			s = getSS(s);
		}
		return s;
	}
	string getSS(const string& s)
	{
		stringstream ss;
		for (auto i = s.begin(); i != s.end() ;)
		{
			char tmp = *i;
			auto j = find_if(i, s.end(),  [&tmp](char x)-> bool
				{
					return x != tmp;
				});
			ss << distance(i, j) << *i;
			i = j;
		}
		return ss.str();
	}
};
int main()
{
	Solution s;
	int n;
	while (cin >> n)
	{
		cout<<s.countAndSay(n)<<endl;

	}
	return 0;
}