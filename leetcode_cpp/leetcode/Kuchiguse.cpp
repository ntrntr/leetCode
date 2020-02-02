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
int main()
{
	int n;
	cin >> n;
	vector<string> f;
	getchar();
	string tmp;
	int minlen = INT_MAX;
	for (int i = 0; i < n; ++i)
	{
		getline(cin, tmp);
		minlen = tmp.length() < minlen ? tmp.length() : minlen;
		reverse(tmp.begin(), tmp.end());
		f.push_back(tmp);
	}
	string res;
	for (int i = 0; i < minlen; ++i)
	{
		char prev = f[0][i];
		int flag = 1;
		for (int j = 1; j < n; ++j)
		{
			if (prev != f[j][i])
			{
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			res.push_back(prev);
		}
	}
	reverse(res.begin(), res.end());
	if (res.length() == 0)
	{
		cout << "nai" << endl;
	}
	else
	cout << res << endl;
	return 0;
}