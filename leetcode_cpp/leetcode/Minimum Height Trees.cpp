#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <queue>
using namespace std;
class Solution {
public:
	vector<int> res;
	int dfs(int start, vector<int>& data, int n, vector<vector<int>>& adjacentList, bool flag = false)
	{
		if (!flag)
		{
			vector<int> visited(n, 0);
			visited[start] = 1;
			queue<int> cur, next;
			cur.push(start);
			int count = 1;
			int idx = 0;
			while (!cur.empty())
			{
				while (!cur.empty())
				{

					int tmp = cur.front();
					cur.pop();
					visited[tmp] = 1;
					for (auto i : adjacentList[tmp])
					{
						if (!visited[i])
						{
							data[i] = max(data[i], count);
							idx = i;
							next.push(i);
						}
					}
				}
				count++;
				swap(cur, next);
			}
			return idx;
		}
		else
		{
			vector<int> visited(n, 0);
			visited[start] = 1;
			queue<int> cur, next;
			cur.push(start);
			int count = 1;
			int minvalue = data[start];
			res.push_back(start);
			while (!cur.empty())
			{
				while (!cur.empty())
				{

					int tmp = cur.front();
					cur.pop();
					visited[tmp] = 1;
					for (auto i : adjacentList[tmp])
					{
						if (!visited[i])
						{
							data[i] = max(data[i], count);
							if (minvalue > data[i])
							{
								res.clear();
								res.push_back(i);
								minvalue = data[i];
							}
							else if (minvalue == data[i])
							{
								res.push_back(i);
							}
							next.push(i);
						}
					}
				}
				count++;
				swap(cur, next);
			}
			return 0;
		}
		
	}
	vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
		vector<vector<int>> adjacentList(n);
		for (auto& i : edges)
		{
			adjacentList[i.first].push_back(i.second);
			adjacentList[i.second].push_back(i.first);
		}
		
		vector<int> data(n, 0);
		int idx = dfs(0, data, n, adjacentList);
		idx = dfs(idx, data, n, adjacentList);
		idx = dfs(idx, data, n, adjacentList, true);
		return res;
	}
};
int main()
{
	Solution s;
	vector<pair<int, int>> edges{ make_pair(3, 0), make_pair(1, 3), make_pair(2, 3) ,make_pair(3, 4), make_pair(4, 5)};
	for each (int var in s.findMinHeightTrees(6, edges))
	{
		cout << var << endl;
	}
	
	return 0;
}