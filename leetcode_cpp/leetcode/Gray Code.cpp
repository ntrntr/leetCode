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
	vector<int> grayCode(int n) {
		vector<int> result;
		result.push_back(0);
		for (int i = 0; i < n; i++) {
			const int highest_bit = 1 << i;
			for (int j = result.size() - 1; j >= 0; j--) // 要反着遍历，才能对称
				result.push_back(highest_bit | result[j]);
		}
		for (auto i:result)
		{
			cout<<i<<" ";
		}
		return result;
	}
	/*vector<int> grayCode(int n)
	{
		vector<int> res;
		const size_t size = 1<<n;
		res.resize(size);
		for (size_t i = 0; i < size; ++i)
		{
			res.push_back(binary_to_gray(i));
		}
	}
	static unsigned int binary_to_gray(unsigned int x)
	{
		return x ^ (x >> 1);
	}
	static unsigned int gray_to_binary(unsigned int x)
	{
		for (unsigned int mask = x >> 1; mask != 0; mask >> 1)
		{
			x = x ^ mask;
		}
		return x;
	}*/
	//vector<int> grayCode(int n) {
	//	vector<int> res;
	//	if (n == 0)
	//	{
	//		res.push_back(0);
	//		return res;
	//	}
	//	vector<vector<int>> tmp(2);
	//	tmp[0].push_back(0);
	//	tmp[1].push_back(1);
	//	for (int i = 2; i <= n; ++i)
	//	{
	//		const int cc = tmp.size();
	//		for (int j = 0; j < cc; ++j)
	//		{
	//			tmp.push_back(tmp[cc - j - 1]);
	//		}
	//		int count = 0, size = tmp.size()/2;
	//		for_each(tmp.begin(), tmp.end(),[&count, &size](vector<int>& n)
	//		{
	//			n.push_back((count++ < size)? 0:1);
	//		});
	//		

	//	}
	//	int bton[32];
	//	bton[0] = 1;
	//	for (int i = 1; i < 32; ++i)
	//	{
	//		bton[i] = bton[i - 1] * 2;
	//	}
	//	for (auto i:tmp)
	//	{
	//		int sum = 0;
	//		int size = i.size();
	//		int myi = 0;
	//		for (auto it = i.begin(); it != i.end(); ++it, ++myi)
	//		{
	//			sum += bton[myi] * (*it);
	//		}
	//		res.push_back(sum);
	//		//cout<<sum<<endl;
	//	}
	//	return res;
	//}
};
int main()
{
	Solution s;
	int n;
	while (cin>>n)
	{
		s.grayCode(n);
		cout<<endl;
	}
	
	return 0;
}