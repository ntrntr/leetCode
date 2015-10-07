#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
class Solution {
public:
	//vector<int> spiralOrder(vector<vector<int>>& matrix) {
	//	vector<int> res;
	//	int row = matrix.size();
	//	int col  = matrix[0].size();
	//	int direction = 0;
	//	int offset = 0;
	//	int flag = 0;
	//	while (1)
	//	{
	//		flag = 0;
	//		//ср
	//		if (direction == 0)
	//		{
	//			
	//			for (int i = 0 + offset; i < col - offset; ++i)
	//			{
	//				res.push_back(matrix[offset][i]);
	//				flag = 1;
	//			}
	//			direction = 1;
	//			if (flag)
	//			{
	//				continue;
	//			}
	//			else
	//				break;
	//		}
	//		//xia
	//		else if (direction == 1)
	//		{
	//			for (int i = 1 + offset ; i < row - offset; ++i)
	//			{
	//				res.push_back(matrix[i][col - offset - 1]);
	//				flag = 1;
	//			}
	//			direction = 2;
	//			if (flag)
	//			{
	//				continue;
	//			}
	//			else
	//				break;
	//		}
	//		//zuo
	//		else if (direction == 2)
	//		{
	//			for (int i = col - offset - 2; i >= offset; --i)
	//			{
	//				res.push_back(matrix[row - offset - 1][i]);
	//				flag = 1;
	//			}
	//			direction = 3;
	//			if (flag)
	//			{
	//				continue;
	//			}
	//			else
	//				break;
	//		}
	//		//shang
	//		else if (direction == 3)
	//		{
	//			for (int i = row - offset - 2; i > offset ; --i)
	//			{
	//				res.push_back(matrix[i][offset]);
	//				flag = 1;
	//			}
	//			direction = 0;
	//			++offset;
	//			if (flag)
	//			{
	//				continue;
	//			}
	//			else
	//				break;
	//			
	//		}
	//	}
	//	return res;
	//}
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> res;
		if (matrix.size() <= 0)
		{
			return res;
		}
		int beginX = 0, endX = matrix.size() - 1;
		int beginY = 0, endY = matrix[0].size() - 1;

		while (true)
		{
			//you
			for (int i = beginY; i <= endY; ++i)
			{
				res.push_back(matrix[beginX][i]);
			}
			if (++beginX > endX)
			{
				break;
			}

			//xia
			for (int i = beginX; i <= endX; ++i)
			{
				res.push_back(matrix[i][endY]);
			}
			if (beginY > --endY )
			{
				break;
			}

			//zuo
			for (int i = endY; i >= beginY; --i)
			{
				res.push_back(matrix[endX][i]);
			}
			if (beginX > --endX)
			{
				break;
			}
			//shang
			for (int i = endX; i >= beginX; --i)
			{
				res.push_back(matrix[i][beginY]);
			}
			if (++beginY > endY)
			{
				break;
			}

		}
		return res;
	}
};
int main()
{
	Solution s;
	vector<vector<int> > ss;
	int a[3][4] = {{ 1, 2, 3 ,4},
	{ 4, 5, 6 ,7},
	{ 7, 8, 9,10 }};
	ss.resize(3);
	for (int i = 0; i < 3; ++i)
	{
		for ( int j = 0; j < 4; ++j)
		{
			ss[i].push_back(a[i][j]);
		}
	}
	vector<int> res = s.spiralOrder(ss);
	for (auto i : res)
	{
		cout<<i<<" ";
	}
	return 0;
}