#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <unordered_map>
#include <sstream>
using namespace std;
class Solution {
public:
	string largestNumber(vector<int>& nums) {
		vector<string> res;
		transform(nums.begin(), nums.end(), back_inserter(res), [this](int x)-> string
		{
			return this->myitoa(x);
		});
		sort(res.begin(), res.end(), [](string& a, string& b)
		{
			return (a + b) > (b + a);
		});
		string data;
		for (auto i:res)
		{
			data += i;
		}
		return data;
	}
	string myitoa(int x)
	{
		stringstream os;
		os << x;
		string res;
		os >> res;
		return res;
	}
};
int main()
{
	Solution s;
	int a[] = { 1, 21, 33, 55, 98 };
	vector<int> f(a, a + 5);
	cout << s.largestNumber(f) << endl;
	return 0;
}