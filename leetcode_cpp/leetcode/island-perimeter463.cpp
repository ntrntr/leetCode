
#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
	int row;
	int cols;
	int ret;
public:
	inline int getData(const vector<vector<int>>& grid, int x, int y, vector<vector<bool>>& isVisited)
	{
		if (!(x >= 0 && x < row && y >= 0 && y < cols))
		{
			return 1;
		}
		if (grid[x][y] == WATER)
		{
			return 1;
		}
		return 0;
	}
	inline void dfs(const vector<vector<int>>& grid, int x, int y, vector<vector<bool>>& isVisited)
	{


		if (!(x >= 0 && x < row && y >= 0 && y < cols))
		{
			return;
		}

		if (!isVisited[x][y] && grid[x][y] == LAND)
		{
			isVisited[x][y] = true;
			ret += getData(grid, x + 1, y, isVisited);
			ret += getData(grid, x - 1, y, isVisited);
			ret += getData(grid, x, y + 1, isVisited);
			ret += getData(grid, x, y - 1, isVisited);
			dfs(grid, x + 1, y, isVisited);
			dfs(grid, x - 1, y, isVisited);
			dfs(grid, x, y + 1, isVisited);
			dfs(grid, x, y - 1, isVisited);
		}

				
	}

	int islandPerimeter(std::vector<std::vector<int>>& grid) {
		int x;
		int y;
		 row = grid.size();
		 cols = grid[0].size();
		std::vector<std::vector<bool>> isVisited(row, std::vector<bool>(cols));
		findALand(grid, x, y);
		ret = 0;
		dfs(grid, x,y, isVisited);
		return ret;
	}

	inline void findALand(const vector<vector<int>>& grid, int& x, int& y)
	{

		x = 0;
		y = 0;
		bool quit = false;
		for (int i = 0; i < row && !quit; ++i)
		{
			for (int j = 0; j < cols && !quit; ++j)
			{
				if (grid[i][j] == LAND)
				{
					x = i;
					y = j;
					quit = true;
				}
			}
		}
		return;
	}

private:
	static constexpr  int LAND = 1;
	static constexpr int WATER = 0;
};


void do_work()
{
	Solution s;
	vector<vector<int>> test
	{
		{ 0,1,0,0 },
		{1,1,1,0},
		{0,1,0,0},
		{1,1,0,0}
	};
	_ASSERTE(s.islandPerimeter(test) == 16);
}

void do_work1()
{
	Solution s;
	vector<vector<int>> test
	{
		{ 0,1,0,0 },
	{ 1,1,1,0 },
	{ 0,1,0,0 },
	{ 1,1,1,0 }
	};
	_ASSERTE(s.islandPerimeter(test) == 18);
}
void do_work2()
{
	Solution s;
	vector<vector<int>> test
	{
		{ 0,1,0,0 },
	{ 1,1,1,0 },
	{ 0,1,0,0 },
	{ 1,1,1,1 }
	};
	_ASSERTE(s.islandPerimeter(test) == 20);
}

void do_work3()
{
	Solution s;
	vector<vector<int>> test
	{
		{1}
	};
	_ASSERTE(s.islandPerimeter(test) == 4);
}

int main(int argc, char* argv[])
{
	do_work();
	do_work1();
	do_work3();
	return 0;
}
