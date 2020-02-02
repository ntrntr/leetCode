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
int getNum(vector<char>& s)
{
	int res = 0;
	int flag = false;
	int icount = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == '.' && !flag)
		{
			flag = true;
			icount++;
		}
		else if (flag && s[i] == '.')
		{
			icount++;
		}
		else if (flag && s[i] != '.')
		{
			if (icount >= 2)
			{
				res += icount - 1;
			}
			flag = false;
			icount = 0;
		}
	}
	if (icount >= 2)
	{
		res += icount - 1;
	}
	return  res;
}
int main()
{
	RAND_MAX
	int n, m;
	cin >> n >> m;
	vector<char> str;
	getchar();
	char c;
	while ((c = getchar()) != '\n')
	{
		str.push_back(c);
	}
	for (int i = 0; i < m; ++i)
	{
		int a;
		char b;
		cin >> a >> b;
		str[a - 1] = b;
		cout << getNum(str) << endl;
	}
	return 0;
}