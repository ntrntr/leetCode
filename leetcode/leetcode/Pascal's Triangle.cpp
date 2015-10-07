#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int> > res;
		if (numRows <= 0)
		{
			return res;
		}
		res.resize(numRows);
		for (int i = 0; i < numRows; ++i)
		{
			for (int j = 0; j <= i; ++j)
			{
				if (j == 0 || j == i)
				{
					res[i].push_back(1);
				}
				else
				{
					res[i].push_back(res[i-1][j-1] + res[i-1][j]);
				}
			}
		}
		return res;
	}
};
int main()
{
	Solution s;
	vector<vector<int> > res = s.generate(5);
	for (auto i:res)
	{
		for(auto j:i)
		{
			cout<<j<<" ";
		}
		cout<<endl;
	}
	return 0;
}