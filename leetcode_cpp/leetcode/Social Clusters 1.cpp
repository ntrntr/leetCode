#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <unordered_map>
#include <limits.h>
#include <set>
using namespace std;
struct myset
{
	set<int> f;
	int num;
	myset() :num(0){};
};
bool cmp(myset& a, myset& b)
{
	return a.num > b.num;
}
int main()
{
	int i, j, k;
	int n,m,c,pos;
	vector<myset> f;
	cin >> n;
	vector<int> tmp;
	for (i = 0; i < n; ++i)
	{
		tmp.clear();
		scanf("%d:", &m);
		for (j = 0; j < m; ++j)
		{
			cin >> c;
			tmp.push_back(c);
		}
		vector<int> insertpos;
		for (j = 0; j < f.size(); ++j)
		{
			for (k = 0; k < tmp.size(); ++k)
			{
				if (f[j].f.find(tmp[k])!= f[j].f.end())
				{
					insertpos.push_back(j);
					break;
				}
			}
		}
		if (insertpos.size() == 0)
		{
			myset m;
			m.num = 1;
			m.f.insert(tmp.begin(), tmp.end());
			f.push_back(m);
		}
		else if (insertpos.size() >= 1)
		{
			int pos = insertpos[0];
			f[pos].num++;
			f[pos].f.insert(tmp.begin(), tmp.end());
			for (j = 1; j < insertpos.size(); ++j)
			{
				f[pos].num += f[insertpos[j]].num;
				f[insertpos[j]].num = 0;
				f[pos].f.insert(f[insertpos[j]].f.begin(), f[insertpos[j]].f.end());
			}
			for (j = 0; j < f.size();)
			{
				if (f[j].num == 0)
				{
					f.erase(f.begin() + j);
				}
				else
					j++;
			}
		}
	}
	sort(f.begin(), f.end(), cmp);
	cout << f.size() << endl;
	for (i = 0; i < f.size(); ++i)
	{
		if (i == 0)
		{
			cout << f[i].num;
		}
		else
			cout << " " << f[i].num;
	}
	return 0;
}