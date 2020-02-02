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
	string getPermutation(int n, int k) {
		vector<char> tmp(n);
		int count = 1;	
		k = k % factorial(n);
		for_each(tmp.begin(), tmp.end(), [&count](char& x){ x = '0' + count++;});
		/*while(k--)
		{
		next_permutation(tmp.begin(), tmp.end());
		}
		string res(tmp.begin(),tmp.end());*/
		string s(tmp.begin(), tmp.end());
		return kth_permutation(s, k);
	}
	template<typename Sequence>
	Sequence kth_permutation(const Sequence& q, int k)
	{
		Sequence tmp(q);
		Sequence res;
		const int n = q.size();
		int base = factorial(n - 1);
		--k;
		for (int i = n - 1; i >0;k = k % base, base = base / i, --i)
		{
			auto pos = next(tmp.begin(), k / base);
			res.push_back(*pos);
			tmp.erase(pos);
		}
		res.push_back(tmp[0]);
		return res;
	}
	int factorial(int x)
	{
		int result = 1;
		for (int i = 1; i <= x; ++i)
		{
			result *= i;
		}
		return result;
	}
};
int main()
{
	Solution s;
	cout<<s.getPermutation(4,4);
	return 0;
}