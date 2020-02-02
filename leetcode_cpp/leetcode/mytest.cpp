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
vector<string> stov(string& str)
{
	vector<string> res;
	string tmp = "";
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] != '/')
		{
			tmp += str[i];
		}
		else
		{
			if (tmp.size() > 0)
			{
				res.push_back(tmp);
				tmp = "";
			}
		}
	}
	if (tmp.size() > 0)
	{
		res.push_back(tmp);
		tmp = "";
	}
	return res;
}
string splitstr(string& a, string& b)
{
	string res;
	vector<string> lhs = stov(a);
	vector<string> rhs = stov(b);
	int lcount = 0, rcount = 0;
	while (lcount < lhs.size() && rcount < rhs.size())
	{
		if (lhs[lcount] == rhs[rcount])
		{
			lcount++;
			rcount++;
		}
		else
			break;
	}
	lcount = lhs.size() - lcount - 1;
	for (int i = 0; i < lcount; ++i)
	{
		res += "../";
	}
	for (int i = rcount; i < rhs.size(); ++i)
	{
		res += rhs[i];
		if (i != rhs.size() - 1)
		{
			res += "/";
		}
	}
	return res;
}
int main()
{
	string a, b;
	cin >> a >> b;
	cout << splitstr(a, b) << endl;
	return 0;
}