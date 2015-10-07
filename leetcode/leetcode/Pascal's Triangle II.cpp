#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> res;
		if (rowIndex <= 0)
		{
			return res;
		}
		res.resize(rowIndex, 1);
		for (int i = 0; i < rowIndex; ++i)
		{
			for (int j =  i / 2; j >= 1; --j)
			{
				res[j] += res[j-1]; 
				res[i - j] = res[j];
			}
			
		}
		return res;
	}
};
class Solution1 {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> res;
		for (int i = 0; i <= rowIndex; ++i)
		{
			for (int j =  i - 1; j > 0; --j)
			{
				res[j] += res[j - 1];
			}
			res.push_back(1);

		}
		return res;
	}
};
int main()
{
	Solution s;
	vector<int> res = s.getRow(3);
	for (auto i:res)
	{
		cout<<i<<" ";
	}
	return 0;
}