#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
using namespace std;
map<string, int> isAdd;
void insertWord(string s, set<string>& res)
{
	sort(s.begin(), s.end());
	if (isAdd[s])
	{
		return;
	}
	res.insert(s);
	while (next_permutation(s.begin(), s.end()))
	{
		res.insert(s);
	}
	isAdd[s] = 1;
	return;
}
int main1()
{
	string s;
	cin >> s;
	set<string> res;
	insertWord(s, res);
	for (int i = 0; i < s.size(); ++i)
	{
		string tmp = s;
		s[i] = 'a';
		insertWord(s, res);
		s[i] = 'b';
		insertWord(s, res);
		s[i] = 'c';
		insertWord(s, res);
		s[i] = 'd';
		insertWord(s, res);
		s = tmp;
	}
	for (auto i:res)
	{
		cout << i << endl;
	}
	return 0;
}