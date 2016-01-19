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
char lowerCase(char x)
{
	if (x >='A' && x <= 'Z')
	{
		return ('a' + (x - 'A'));
	}
	return x;
}
int main()
{
	string str,tmp;
	vector<string> maxstr;
	int maxcount = 0;
	unordered_map<string, int> f;
	getline(cin, str);
	for (int i = 0; i < str.size(); ++i)
	{
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9'))
		{
			tmp.push_back(lowerCase(str[i]));
		}
		else
		{
			if (tmp.size() == 0)
			{
				continue;
			}
			else
			{
				++f[tmp];
				if (f[tmp]>maxcount)
				{
					maxstr.clear();
					maxstr.push_back(tmp);
					maxcount = f[tmp];
				}
				else if (f[tmp] == maxcount)
				{
					maxstr.push_back(tmp);
				}
				tmp.clear();
			}
		}
	}
	sort(maxstr.begin(), maxstr.end());
	cout << maxstr[0] << " " << maxcount;
	return 0;
}