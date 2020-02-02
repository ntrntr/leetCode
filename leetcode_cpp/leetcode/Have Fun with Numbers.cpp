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
	vector<int> f;
	vector<int> g;
	string str;
	cin >> str;
	for (auto i:str)
	{
		f.push_back(i - '0');
	}
	int jinwei = 0;
	for (int i = f.size() - 1; i >= 0; --i)
	{
		g.push_back((f[i] * 2 + jinwei) % 10);
		jinwei = (f[i] * 2 + jinwei) / 10;
	}
	if (jinwei > 0)
	{
		g.push_back(jinwei);
	}
	vector<int> tmp1(f);
	vector<int> tmp2(g);
	sort(tmp1.begin(), tmp1.end());
	sort(tmp2.begin(), tmp2.end());
	if (tmp1 == tmp2)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	reverse(g.begin(), g.end());
	for (auto i:g)
	{
		cout << i;
	}
	return 0;
}