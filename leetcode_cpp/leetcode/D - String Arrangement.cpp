#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;
bool judge(string& s)
{
	for (int i = 1; i < s.size(); ++i)
	{
		if (s[i-1] == s[i])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	string s;
	cin>>s;
	vector<string> res;
	sort(s.begin(), s.end());
	if (judge(s))
	{
		cout<<s<<endl;
		return 0;
	}
	while (next_permutation(s.begin(), s.end()))
	{
		if (judge(s))
		{
			cout<<s<<endl;
			return 0;
		}
	}
	cout<<"-1"<<endl;
	return 0;
}