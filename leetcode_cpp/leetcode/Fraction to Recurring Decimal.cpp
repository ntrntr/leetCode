#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <sstream>
#include <unordered_map>
using namespace std;
class Solution {
public:
	string fractionToDecimal(int a, int b) {
		string res = "";
		long long int numerator = a;
		long long int denominator = b;
		if (numerator * denominator < 0)
		{
			res += "-";
			
		}
		numerator = numerator > 0 ? numerator : -numerator;
		denominator = denominator > 0 ? denominator : -denominator;
		if (numerator / denominator > 0)
		{
			res += myitoa(numerator / denominator);
		}
		else
		{
			res += "0";
		}
		if (numerator % denominator == 0)
		{
			return res;
		}
		else
		{
			res += ".";
		}
		numerator = numerator % denominator;
		unordered_map<long int,long int> f;
		long int count = 0;
		while (f.find(numerator) == f.end() && numerator != 0)
		{
			f[numerator] = count++;
			res += myitoa(numerator * 10 / denominator);
			numerator = (numerator * 10 % denominator);
		}
		if (numerator == 0)
		{
			//return res;
		}
		else
		{
			size_t pos = res.find('.');
			res.insert(pos + f[numerator] + 1, "(");
			res.push_back(')');
		}
		return res;
	}
	string myitoa(long long int x)
	{
		string res;
		stringstream os;
		os << x;
		os >> res;
		return res;
	}
	vector<string> findRepeatedDnaSequences(string s) {
		vector<string> res;
		if (s.size() < 20)
		{
			return res;
		}
		for (int i = 0; i < s.size() - 10; ++i)
		{
			string tmp(s.begin() + i, s.begin() + i + 10);
			if (find(res.begin(), res.end(), tmp) != res.end())
			{
				continue;
			}
			if (s.find(tmp, i + 10) != string::npos)
			{
				res.push_back(tmp);
			}
		}
		return res;
	}
	int rob(vector<int>& nums) {
		result = 0;
		if (nums.size() <= 2)
		{
			for (int i = 0; i < nums.size(); ++i)
			{
				result = max(result, nums[i]);
			}
			return result;
		}
		vector<int> f(nums.size(), 0);
		f[0] = nums[0];
		f[1] = max(nums[0], nums[1]);
		for (int i = 2; i < nums.size(); ++i)
		{
			f[i] = max(f[i - 1], f[i - 2] + nums[i]);
		}
		return f[nums.size()- 1];
	}
	void mydp(int pos, int cooldown, int res, vector<int>& nums)
	{
		if (pos >= nums.size())
		{
			result = max(result, res);
			return;
		}
		//steal
		if (cooldown == 0)
		{
			mydp(pos + 1, 1, res + nums[pos], nums);
		}
		

		//nosteal
		mydp(pos + 1, 0, res, nums);
		
	}
	int result;

};
union MyUnion
{
	char a;
	int b;
	long c;
	char d[2];
	char geta() const
	{
		return a;
	}
};
int main()
{
	Solution s;
	//vector<int> f{ 183, 219, 57, 193, 94, 233, 202, 154, 65, 240, 97, 234, 100, 249, 186, 66, 90, 238, 168, 128, 177, 235, 50, 81, 185, 165, 217, 207, 88, 80, 112, 78, 135, 62, 228, 247, 211};
	/*int tmp;
	while (cin>>tmp)
	{
		f.push_back(tmp);
		
	}*/
	//cout << s.rob(f) << endl;
	MyUnion test;
	test.a = 'b';
	cout << sizeof(test) << endl;
	cout << test.geta() << endl;
	return 0;
}