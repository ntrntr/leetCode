#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;
struct node
{
	int x;
	int y;
	char val;
	node(int a, int b, char c):x(a), y(b), val(c){};

};
int n,m;
class Solution {
public:
	vector<node> getRect(vector<vector<char>>& data)
	{
		vector<node> res;
		vector<vector<bool> > visited(n, vector<bool>(m, false));
		myFuc(0 , 0, data, res, visited);
		for (auto i: res)
		{
			cout<<i.val<<" "<<i.x + 1<<" "<<i.y + 1<<endl;
		}
		return res;
	}
	void myFuc(int x, int y, vector<vector<char>>& data, vector<node>& res, vector<vector<bool> >& visited)
	{
		if (x >= n || y >= m || visited[x][y])
		{
			return;
		}
		char c = data[x][y];
		int right,bottom;
		for (int i = y; i < m; ++i)
		{
			if (data[x][i] == c)
			{
				right = i;
			}
			else
				break;
		}

		for (int i = x; i < n; ++i)
		{
			if (data[i][y] == c)
			{
				bottom = i;
			}
			else
				break;
		}
		for (int i = x; i <= bottom; ++i)
		{
			for (int j = y; j <= right; ++j)
			{
				visited[i][j] = true;
			}
		}
		res.push_back(node(x, y, c));
		myFuc(x, right + 1, data, res, visited);
		myFuc(bottom + 1, y, data, res, visited);

	}
};
int main()
{

	cin>>n>>m;
	vector<vector<char>> f(n, vector<char>(m));
	
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin>>f[i][j];
		}
	}
	Solution s;
	s.getRect(f);
	return 0;
}