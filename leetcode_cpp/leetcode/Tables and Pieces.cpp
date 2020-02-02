#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <unordered_map>
#include <limits.h>
using namespace std;
int res = 0;
void GetWaysOfPieces(int level,int c, vector<vector<int>>& board, vector<int>& rows, vector<int>& cols)
{
	if (level >= 6)
	{
		bool flag = false;
		for (int i = 0; i < 6; ++i)
		{
			if (cols[i] != 3)
			{
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			res++;
		}
		return;
	}
	if (rows[level] > 3)
	{
		return;
	}
	if (rows[level] == 3)
	{
		GetWaysOfPieces(level + 1,0 ,board, rows, cols);
	}
	else
	{
		for (int i = c; i < 6; ++i)
		{
			if (board[level][i] == 1)
			{
				continue;
			}
			else if (cols[i] + 1 > 3)
			{
				continue;
			}
			else
			{
				rows[level]++;
				cols[i]++;
				board[level][i] = 1;
				GetWaysOfPieces(level, i + 1 ,board, rows, cols);
				board[level][i] = 0;
				cols[i]--;
				rows[level]--;
			}
		}
	}
}

int main()
{
	vector<vector<int>> board(6, vector<int>(6, 0));
	vector<int> rows(6, 0);
	vector<int> cols(6, 0);
	bool flag = false;
	string tmp;
	for (int i = 0; i < 6; ++i)
	{
		cin >> tmp;
		for (int j = 0; j < tmp.size(); ++j)
		{
			if (tmp[j] == 'o')
			{
				board[i][j] = 1;
				flag = (++rows[i]) > 3 ? true : false;
				flag = (++cols[j]) > 3 ? true : false;
			}
		}
	}
	if (flag)
	{
		cout << 0 << endl;
		return 0;
	}
	GetWaysOfPieces(0,0, board, rows, cols);
	cout << res << endl;
	return 0;
}