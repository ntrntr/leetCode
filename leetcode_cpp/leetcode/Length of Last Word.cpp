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
	int lengthOfLastWord(string s) {
		//int len = 0;
		//for (auto i = s.begin(); i != s.end(); )
		//{
		//	auto j = find(i, s.end(), ' ');
		//	len = distance(i, j);
		//	if (j == s.end())
		//	{
		//		return len;
		//	}
		//	while (j != s.end() && *j == ' ')
		//	{
		//		j++;
		//	}
		//	i = j;
		//}
		//return len;
		auto a = find_if(s.rbegin(), s.rend(), ::isalpha);
		auto b = find_if_not(a, s.rend(), ::isalpha);
		return distance(a, b);
	}
};
int main()
{
	Solution s;
	string tmp;

	while (getline(cin,tmp))
	{
		cout<<s.lengthOfLastWord(tmp)<<endl;
	}
	return 0;
}