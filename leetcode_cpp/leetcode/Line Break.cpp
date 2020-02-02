#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <unordered_map>
#include <limits.h>
using namespace std;
void SplitByCommas(string& s)
{
	vector<string> res;
	auto it = s.find(',');
	while (it != string::npos)
	{
		res.push_back(s.substr(0, it));
		s = s.substr(it + 1);
		it = s.find(',');
	}
	res.push_back(s);
	for (auto i:res)
	{
		cout << i << endl;
	}
}
int main()
{
	string s;
	cin >> s;
	SplitByCommas(s);
	return 0;
}