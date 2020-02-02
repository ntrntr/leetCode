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
int main()
{
	int N, M;
	cin >> N >> M;
	int id, k, tmp;
	map<int, vector<int>> tree;
	
	for (int i = 0; i < M; ++i)
	{
		cin >> id >> k;
		for (int j = 0; j < k; ++j)
		{
			cin >> tmp;
			tree[id].push_back(tmp);
		}
	}
	deque<int> cur, next;
	cur.push_back(1);
	int maxlevel, maxnum = 0;
	int c = 1;
	while (!cur.empty())
	{
		if (maxnum < cur.size())
		{
			maxnum = cur.size();
			maxlevel = c;
		}
		while (!cur.empty())
		{
			int a = cur.back();
			cur.pop_back();
			for (auto i:tree[a])
			{
				next.push_back(i);
			}
		}
		swap(cur, next);
		++c;
	}
	cout << maxnum << " " << maxlevel << endl;
	return 0;
}