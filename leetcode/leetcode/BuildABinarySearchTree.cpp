#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
struct node
{
	int val;
	int left;
	int right;
	node():val(-1),left(-1),right(-1)
	{}
};
int indexx = 0;
void insertNum(int root, vector<node>& f, vector<int>& num)
{
	if (f[root].left != -1)
	{
		insertNum(f[root].left, f, num);
	}
	f[root].val = num[indexx++];
	if (f[root].right != -1)
	{
		insertNum(f[root].right, f, num);
	}
}
int main()
{
	int n;
	cin>>n;
	vector<node> f(n);
	vector<int> num(n);
	int tmpleft,tmpright;
	for (int i = 0; i < n; ++i)
	{
		cin>>tmpleft>>tmpright;
		f[i].left = tmpleft;
		f[i].right = tmpright;
	}
	for (int i = 0; i < n; ++i)
	{
		cin>>num[i];
	}
	sort(num.begin(), num.end());
	insertNum(0, f, num);
	queue<int> cur,next;
	cur.push(0);
	vector<int> res;
	while (!cur.empty())
	{
		while (!cur.empty())
		{
			int tmp = cur.front();
			cur.pop();
			res.push_back(f[tmp].val);
			if (f[tmp].left != -1)
			{
				next.push(f[tmp].left);
			}
			if (f[tmp].right != -1)
			{
				next.push(f[tmp].right);
			}
		}
		swap(cur, next);
	}
	for (int i = 0; i < n; ++i)
	{
		if (i == 0)
		{
			cout<<res[i];
		}
		else
		{
			cout<<" "<<res[i];
		}
	}
	return 0;
}