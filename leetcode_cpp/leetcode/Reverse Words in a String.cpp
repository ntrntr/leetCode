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
	void reverseWords(string &s) {
		vector<string> res;
		auto prev = s.begin();
		auto it = find(s.begin(), s.end(), ' ');
		while (it != s.end())
		{
			if (prev == it)
			{
				prev = it + 1;
				it = find(prev, s.end(), ' ');
				continue;
			}
			else
			{
				string ss(prev, it);
				res.push_back(ss);
				prev = it + 1;
				it = find(prev, s.end(), ' ');
			}
			

		}
		if (prev != it)
		{
			string ss(prev, it);
			res.push_back(ss);
		}
		string tmp;
		for (auto it = res.rbegin(); it != res.rend(); ++ it)
		{
			if(it == res.rend() - 1)
			{
				tmp += *it;
			}
			else
				tmp += *it + " ";
		}
		s = tmp;
		return ;
	}
};
int main()
{
	Solution s;
	string ss("a");
	s.reverseWords(ss);
	cout<<ss<<endl;
	return 0;
}