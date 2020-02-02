#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;
class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		reverse(digits.begin(), digits.end());
		int last = 1;
		for(int i = 0; i < digits.size(); ++i)
		{
			digits[i] = (digits[i] + last);
			last = digits[i] / 10;
			digits[i] %= 10;	
			if(last == 0)
				break;
		}
		if(last != 0)
		{
			digits.push_back(last);
		}
		reverse(digits.begin(), digits.end());
		return digits;

	}
};
int main()
{
	Solution s;
	int a[] = {0};
	vector<int> ss(a, a + 1);
	for (auto i:s.plusOne(ss))
	{
		cout<<i<<" ";
	}
	return 0;
}