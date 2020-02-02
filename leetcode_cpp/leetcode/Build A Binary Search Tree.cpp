#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <unordered_map>
#include <limits.h>
#include <deque>
using namespace std;
int n;
int num = 0;
struct node
{
	node(){};
	node(int a, int b, int c) :left(a), right(b), value(c){};
	int left;
	int right;
	int value;
};
void lnr(int index, vector<node>& f, vector<int>& data)
{
	if (index == -1)
	{
		return;
	}
	lnr(f[index].left, f, data);
	f[index].value = data[num++];
	lnr(f[index].right, f, data);
}
void myorder(vector<node>&f, vector<int>& res)
{
	deque<int> cur, next;
	cur.push_back(0);
	while (!cur.empty())
	{
		while (!cur.empty())
		{
			int a = cur.front();
			cur.pop_front();
			res.push_back(f[a].value);
			if (f[a].left != -1)
			{
				next.push_back(f[a].left);
			}
			if (f[a].right != -1)
			{
				next.push_back(f[a].right);
			}
		}
		swap(cur, next);
	}
}
int main()
{
	cin >> n;
	vector<node> f(n);
	int a, b;
	for (int i = 0; i < n; ++i)
	{
		cin >> a >> b;
		f[i] = node(a, b, 0);
	}
	vector<int> data(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> data[i];
	}
	sort(data.begin(), data.end());
	lnr(0, f, data);
	vector<int> res;
	myorder(f, res);
	for (int i = 0; i < res.size(); ++i)
	{
		if (i == res.size()-1)
		{
			cout << res[i];
		}
		else
		{
			cout << res[i] << " ";
		}
	}
	return 0;
}