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
	int singleNumber(vector<int>& nums) {
		//unordered_map<int, int> f;
		//int res = 0;
		//const int size = sizeof(int) * 8;
		//vector<int> f(size, 0);
		//for_each(nums.begin(), nums.end(), [&f, size](int x)
		//{
		//	for (int i = 0; i < size; ++i)
		//	{
		//		f[i] = (f[i] + (x >> i & 1)) % 3;  
		//	}
		//});

		//for (int i = 0; i < size; ++i)
		//{
		//	res += (f[i] <<i);
		//}
		int one = 0, two = 0, three = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			two |= (one & nums[i]);
			one ^= nums[i];
			three = ~(two & one);
			one &= three;
			two &= three;
		}
		return one;
		/*for_each(nums.begin(), nums.end(),[&f, &res](int x)
		{
			f[x]++;
		});
		for(auto it = f.begin(); it != f.end(); ++it)
		{
			if(it->second == 1)
			{
				return it->first;
			}
		}*/
	}
};
int main()
{
	Solution s;
	int a[] = {2,2,3,2};
	vector<int> f(a, a + 4);
	cout<<s.singleNumber(f)<<endl;
	return 0;
}