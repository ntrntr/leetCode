#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <unordered_map>
using namespace std;
class Solution {
public:
	void gameOfLife(vector<vector<int>>& board) {
		vector<vector<int>> tmp(board);
		const int n = board.size();
		const int m = board.front().size();
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < m; j++)
			{
				int c = getLifeNum(i, j, tmp);
				if (board[i][j] == 1 && c < 2)
				{
					board[i][j] = 0;
				}
				else if (board[i][j] == 1 && (c == 2 || c == 3))
				{
					
				}
				else if (board[i][j] == 1 && c > 3)
				{
					board[i][j] = 0;
				}
				else if (board[i][j] == 0 && c == 3 )
				{
					board[i][j] = 1;
				}
			}
		}
	}
	int getLifeNum(int x, int y, vector<vector<int>>& board)
	{
		
		int sum = 0;
		for (int i = -1; i <= 1; ++i)
		{
			for (int j = -1; j <= 1; ++j)
			{
				if (i == 0 && j == 0)
				{
					continue;
				}
				sum += getData(x + i, y + j, board);
			}
		}
		return sum;
	}
	int getData(int i, int j, vector<vector<int>>& board)
	{
		if (i <0 || i >= board.size() || j < 0 || j >= board.front().size())
		{
			return 0;
		}
		return board[i][j];
	}
	bool isPowerOfTwo(int n) {
		int count = 0;
		while (n)
		{
			count += (n & 1);
			n = n >> 1;
		}
		return count == 1;
	}
};
void myPrintf(const vector<vector<int>>& iv)
{
	for (auto i : iv)
	{
		for (auto j : i)
		{
			cout << j << " ";
		}
		cout << endl;
	}
}
int main()
{
	Solution s;
	vector<vector<int>> iv;
	vector<int> v(2, 1);
	iv.push_back(v);
	v[1] = 0;
	iv.push_back(v);
	myPrintf(iv);
	s.gameOfLife(iv);
	myPrintf(iv);
	return 0;
}