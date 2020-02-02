#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <unordered_map>
#include <functional>
using namespace std;
class Solution {
public:
	vector<int> countSmaller(vector<int>& nums) {
		const int n = nums.size();
		vector<int> res(n, 0);
		vector<int> f(nums.begin(), nums.end());
		sort(f.rbegin(), f.rend());
		vector<int> fcount(n, 0);
		int tmp = n;
		//transform(fcount.begin(), fcount.end(), fcount.begin(), [&tmp](int& x){ return --tmp; });
		generate(fcount.begin(), fcount.end(), [&tmp]()-> int{ return --tmp; });
		//for (auto i:fcount)
		//{
		//	cout << i << " ";
		//}
		//cout << endl;
		for (int i = 0; i < n; ++i)
		{
			auto it = lower_bound(f.begin(), f.end(), nums[i], greater<int>());
			size_t pos = distance(f.begin(), it);
			res[i] = fcount[pos];
			transform(fcount.begin(), fcount.begin() + pos, fcount.begin(), [](int x){ return --x; });
			
		}
		//for (int i = 0; i < n; ++i)
		//{
		//	int count = 0;
		//	for (int j = i + 1; j < n; ++j)
		//	{
		//		if (nums[i] > nums[j])
		//		{
		//			++count;
		//		}
		//	}
		//	res[i] = count;
		//}
		return res;
	}
	int nthSuperUglyNumber(int n, vector<int>& primes) {
		if (n == 1)
		{
			return 1;
		}
		int num = 2;
		//sort(primes.rbegin(), primes.rend());
		for (int i = 2; i <= n; ++i)
		{
			while (!isSuperUglyNumber(num, primes))
			{
				num++;
			}
			if (i == n)
			{
				return num;
			}
			else
				num++;
		}
		return num;
	}
	bool isSuperUglyNumber(int num, vector<int>& primes)
	{
		int index = 0;
		while (index < primes.size() && num != 1)
		{
			if (num % primes[index] == 0)
			{
				num /= primes[index];
			}
			else
				index++;
		}
		return num == 1 ? true : false;
	}
	int maxCoins(vector<int>& nums) {
		int sum = 0;
		getMaxCoins(nums, sum);
		return sum;
	}
	void getMaxCoins(vector<int>& nums, int& sum)
	{
		if (nums.size() == 3)
		{
			sum += getsum(nums, 1);
			nums.erase(nums.begin() + 1);
			
		}
		if (nums.size() == 2 )
		{
			sum += nums[0] * nums[1] + max(nums[0], nums[1]);
			return;
		}
		if (nums.size() == 1)
		{
			sum += nums[0];
			return;
		}
		if (nums.size() == 0)
		{
			return;
		}
		int minindex = 0;
		int minnum = nums[0];
		for (int j = 1; j < nums.size(); ++j)
		{
			if (minnum > nums[j])
			{
				minnum = nums[j];
				minindex = j;
			}
		}
		sum += getsum(nums, minindex);
		nums.erase(nums.begin() + minindex);
		getMaxCoins(nums, sum);
	}
	int getsum(vector<int>& nums, int x)
	{
		return (x - 1 < 0 ? 1 : nums[x - 1]) * nums[x] * (x + 1 >= nums.size() ? 1 : nums[x + 1]);
	}
};

int main()
{
	Solution s;
	//int a[] = { 2,7,13,19 };
	//100000
		//[7, 19, 29, 37, 41, 47, 53, 59, 61, 79, 83, 89, 101, 103, 109, 127, 131, 137, 139, 157, 167, 179, 181, 199, 211, 229, 233, 239, 241, 251]
	vector<int> f{ 9, 76, 64, 21 };
	cout << s.maxCoins(f) << endl;
	f.assign(f.begin(), f.end());
	remove_if(f.begin(), f.end(), [](int x){ return x == 0; });
	fill()
	return 0;
}