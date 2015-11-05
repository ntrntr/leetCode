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
	int n,m;
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		n = matrix.size();
		m = matrix.front().size();
		return search(0,0,matrix, target);
	}
	bool search(int x, int y, vector<vector<int>>& matrix, int target)
	{
		if(x == n - 1 &&  y == m-1)
			return target == matrix[x][y] || matrix[max(0, x-1)][y] == target || matrix[x][max(0,y-1)] == target;
		if(matrix[x][y] == target)
			return true;
		if(matrix[x][y] > target)
		{
			return matrix[max(0, x-1)][y] == target || matrix[x][max(0,y-1)] == target;
		}
		else
		{
			return search(min(x+1, n-1), min(y+1, m-1), matrix, target);
		}
	}
};
int main()
{
	Solution s;
	int a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
	vector<vector<int> > f;
	for (int i = 0; i < 5; ++i)
	{
			vector<int> g(a + 5 * i, a + 5 * i + 5);
			f.push_back(g);
	}
	

	cout<<s.searchMatrix(f, 15)<<endl;
	return 0;
}