#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
class Solution {
public:
	void myPrint(vector<vector<char> >& res)
	{
		for (auto i:res)
		{
			for(auto j:i)
			{
				cout<<j;
			}
			cout<<endl;
		}
		cout<<"-------------------------"<<endl;
	}
	string convert(string s, int numRows) {
		vector<vector<char> > res(numRows);
		int n = s.size();
		int flag = 1;
		int count = 0;
		if (numRows == 1)
		{
			return s;
		}
		for (int i = 0; i < n; ++i)
		{
			if (flag)
			{
				res[count].push_back(s[i]);
				if (count == numRows - 1)
				{
					flag = 0;
					count--;
				}
				else
					count++;
			}
			else
			{
				res[count].push_back(s[i]);
				if (count == 0)
				{
					flag = 1;
					count++;
				}
				else
					count--;
			}
			
		}
		string r;
		for (int i = 0; i < numRows; ++i)
		{
			r.append(res[i].begin(),res[i].end());
		}
		return r;
	}
};
int main()
{
	Solution s;
	cout<<s.convert("ABCDE", 1);
	return 0;
}