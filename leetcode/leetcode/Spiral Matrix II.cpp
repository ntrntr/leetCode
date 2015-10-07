#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int> > matrix(n, vector<int>(n, 0));
		int count = 1;
		int beginX = 0, endX = n - 1;
		int beginY = 0, endY = n - 1;
		while (true)
		{
			//you
			for (int i = beginY; i <= endY; ++i)
			{
				matrix[beginX][i] = count++;
			}
			if (++beginX > endX)
			{
				break;
			}

			//xia
			for (int i = beginX; i <= endX; ++i)
			{
				matrix[i][endY] = count++;
			}
			if (beginY > --endY )
			{
				break;
			}

			//zuo
			for (int i = endY; i >= beginY; --i)
			{
				matrix[endX][i] = count ++ ;
			}
			if (beginX > --endX)
			{
				break;
			}
			//shang
			for (int i = endX; i >= beginX; --i)
			{
				matrix[i][beginY] = count ++;
			}
			if (++beginY > endY)
			{
				break;
			}

		}
		return matrix;
	}
};
int main()
{
	Solution s;
	for (auto i:s.generateMatrix(3))
	{
		for (auto j:i)
		{
			cout<<j<<" ";
		}
		cout<<endl;
	}
	return 0;
}