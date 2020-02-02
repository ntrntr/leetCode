#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

//class Solution {
//public:
//	bool exist(vector<vector<char>>& board, string word) {
//		const int n = board.size();
//		const int m = board[0].size();
//		vector<vector<int> > visited(n, vector<int>(m, 0));
//		for(int i = 0; i < n; ++i)
//		{
//			for(int j = 0; j < m; ++j)
//			{
//				if(dfs(0, i, j, word, board, visited))
//					return true;
//			}
//		}
//		return false;
//	}
//
//	bool dfs(int cur, int x, int y, string& word, vector<vector<char>>& board, vector<vector<int> >& visited)
//	{
//		if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || cur >= word.size() || visited[x][y])
//			return false;
//		if(word[cur] != board[x][y])
//			return false;
//		if(cur == word.size() - 1)
//			return true;
//		visited[x][y] = 1;
//		if (dfs(cur + 1 , x + 1, y, word, board, visited)|| dfs(cur + 1 , x, y + 1, word, board, visited) || dfs(cur + 1 , x - 1, y, word, board, visited) || dfs(cur + 1 , x, y - 1, word, board, visited))
//		{
//			return true;
//		}
//		else
//		{
//			visited[x][y] = 0;
//			return false;
//		}
//
//
//	}
//};
class Solution {
public:
	int mySqrt(int x) {
		int flag = 1;
		if(x == 1 || x== 0)
			return x? 1:0;
		int low = 1,high = x;
		while(low < high)
		{
			int mid = (low + high) / 2;
			if (mid * mid == x)
			{
				return mid;
			}
			if (mid * mid < x)
			{
				low = mid + 1;
			}
			else if (mid * mid > x)
			{
				high = mid - 1;
			}
		}
		return low * low > x ? low - 1 : low;
	}
};
int main()
{
	Solution ss;
	/*string s[] = {"a"};
	vector<vector<char> > f(1);
	for (int i = 0; i < 1; ++i)
	{
	for (int j = 0; j < s[i].size(); ++j)
	{
	f[0].push_back(s[i][j]);
	}
	}
	bool tmp = ss.exist(f, "ab");
	cout<<tmp<<endl;*/
	for(int i = 0; i < 30;i++)
	{
		cout<<ss.mySqrt(i)<<"\t"<<i<<endl;
	}
	
	return 0;
}