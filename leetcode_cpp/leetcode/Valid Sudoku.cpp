#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;
class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		for (int i = 0; i < 9; ++i)
		{
			vector<int> tmp1(10,0);
			vector<int> tmp2(10,0);
			for (int j = 0; j < 9; ++j)
			{
				//row
				if (board[i][j] == '.')
				{
					//continue;
				}
				else if (++tmp1[board[i][j] - '0'] > 1)
				{
					return false;
				}
				//col
				if (board[j][i] == '.')
				{
					//continue;
				}
				else if (++tmp2[board[j][i] - '0'] > 1)
				{
					return false;
				}

			}
		}
		for (int k = 0; k < 9; ++k)
		{
			vector<int> tmp(10, 0);
			for (int i = 0; i < 3; ++i)
			{
				for (int j = 0; j < 3; ++j)
				{
					int x = 3 * (k / 3) + i;
					int y = 3 * (k % 3) + j;
					//cout<<"k = "<<k<<" x = "<<x<<" y = "<<y<<endl;
					if (board[x][y] == '.')
					{
					}
					else if (++tmp[board[x][y] - '0'] > 1)
					{
						return false;
					}
				}
			}
		}
		return true;
	}
};
int main()
{
	Solution s;
	vector<vector<char>> tmp(9, vector<char>(9));
	string ss[] = {"..5.....6","....14...",".........",".....92..","5....2...",".......3.","...54....","3.....42.","...27.6.."};
	for (int i = 0; i < 9; ++i)
	{
		//string s1 = ss[i];
		for (int j = 0; j < 9; ++j)
		{
			tmp[i][j] = ss[i][j];
		}

	}
	cout<<s.isValidSudoku(tmp)<<endl;
	return 0;
}