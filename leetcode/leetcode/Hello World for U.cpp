#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("D://1.txt", "r",stdin);
#endif


	string s;
	cin >> s;
	if (s.size() <= 4)
	{
		cout << s << endl;
		return 0;
	}
	int n1, n2, n3;
	n1 = n3 = (s.size() + 2) / 3;
	n2 = s.size() + 2 - n1 - n3;
	vector<vector<char>> f(n1, vector<char>(n2, ' '));
	int dir = 0;
	for (int i = 0, j = 0, k = 0; i < s.size(); i++)
	{
		f[j][k] = s[i];
		if (dir == 0)
		{
			j++;
			if (j==f.size())
			{
				dir = 1;
				j--;
				k++;
			}
		}
		else if (dir == 1)
		{
			k++;
			if (k == f[0].size())
			{
				dir = 2;
				k--;
				j--;
			}
		}
		else if (dir == 2)
		{
			j--;
			//if (j == -1)
			//{
			//	break;
			//}
		}
	}
	for (auto i : f)
	{
		for (auto j : i)
		{
			cout << j;
		}
		cout << endl;
	}
	return 0;
}