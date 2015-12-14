#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <unordered_map>
#include <set>
using namespace std;
class Solution
{
public:
	Solution();
	~Solution();

private:

};

Solution::Solution()
{
}

Solution::~Solution()
{
}
struct myset
{
	set<int> f;
	int num;
	myset() :num(0){};
};
//void myprintf(vector<myset>& f)
//{
//	cout << "//////////////////////////////////////////////////////////////////////////" << endl;
//	cout << f.size() << endl;
//	for (auto i:f)
//	{
//		cout << "num = " << i.num << " "<<endl;
//		for (auto j:i.f)
//		{
//			cout << j << " ";
//		}
//		cout << endl;
//	}
//	cout << "//////////////////////////////////////////////////////////////////////////_end" << endl;
//}
int main()
{
	Solution s;
	int N;
	cin >> N;
	vector<myset> f;
	int num;
	int tmp;
	if (N <= 0)
	{
		cout << "0" << endl;
		cout << "0";
		return 0;
	}
	for (int i = 0; i < N; ++i)
	{
		scanf("%d: ", &num);
		vector<int> t;
		
		for (int j = 0; j < num; ++j)
		{
			cin >> tmp;
			t.push_back(tmp);
		}
		if (f.size() == 0)
		{
			set<int> mytmp;
			for (auto myi:t)
			{
				mytmp.insert(myi);
			}
			myset tset;
			tset.num = 1;
			tset.f = mytmp;
			f.push_back(tset);
		}
		else
		{
			int k;
			int tmpsize = f.size();
			int flag = 1;
			vector<int> insertpos;
			for (k = 0; k < tmpsize; ++k)
			{
				for (int l = 0; l < t.size(); ++l)
				{
					if (f[k].f.find(t[l]) != f[k].f.end())
					{
						insertpos.push_back(k);
						break;
						//++f[k].num;
						//for (int myl = 0; myl < t.size(); ++myl)
						//{
						//	f[k].f.insert(t[myl]);
						//}
						//flag = 0;
					}
				}
			}
			if (insertpos.size() == 0)
			{
				set<int> mytmp;
				for (auto myi : t)
				{
					mytmp.insert(myi);
				}
				myset tset;
				tset.num = 1;
				tset.f = mytmp;
				f.push_back(tset);
			}
			else if (insertpos.size() == 1)
			{
				int id = insertpos[0];
				++f[id].num;
				f[id].f.insert(t.begin(), t.end());
			}
			else if (insertpos.size() > 1)
			{
				int id = insertpos[0];
				++f[id].num;
				f[id].f.insert(t.begin(), t.end());
				for (int myi = 1; myi < insertpos.size(); ++myi)
				{
					f[id].num += f[myi].num;
					f[id].f.insert(f[myi].f.begin(), f[myi].f.end());
					f[myi].f.clear();
				}
				for (int myi = 0; myi < f.size();)
				{
					if (f[myi].f.size() == 0)
					{
						f.erase(f.begin() + myi);
					}
					else
						myi++;
				}
			}

		}
		//myprintf(f);

	}

	sort(f.begin(), f.end(), [](myset& a, myset& b)
	{
		return a.num > b.num;
	});
	cout << f.size() << endl;
	for (int i = 0; i < f.size(); ++i)
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