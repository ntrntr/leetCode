#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
class Solution {
public:
	string multiply(string num1, string num2) {
		const int n = num1.size();
		const int m = num2.size();
		if (n < m)
		{
			return multiply(num2, num1);
		}
		vector<int> f(n + m, 0);
		vector<int> n1(n, 0);
		vector<int> n2(m, 0);
		int jinwei = 0;
		for (int i = 0; i < n; ++i)
		{
			n1[i] = num1[n - i - 1] - '0';
		}
		for (int i = 0; i < m; ++i)
		{
			n2[i] = num2[m - i - 1] - '0';
		}
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				f[i + j] += (n2[i] * n1[j]);
				f[i + j + 1] += f[i + j]/ 10;
				f[i + j] %= 10; 
				
			}
			
		}
		string res;
		int flag = 1;
		for (int i = m + n -1; i >= 0; --i)
		{
			if (flag && f[i] == 0)
			{
				continue;
			}
			else
			{
				flag = 0;
				res += (f[i] + '0');
			}
		}
		if (flag)
		{
			return "0";
		}
		else
			return res;
	}
};
int main()
{
	string s1,s2;
	Solution s;
	while(cin>>s1>>s2)
	{
		cout<<s.multiply(s1,s2)<<endl;
	}
	return 0;
}