#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <functional>
using namespace std;
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		do 
		{
			for (auto i:nums)
			{
				cout<<i<<" ";
			}
			cout<<endl;
		} while (next_permutation(nums.begin(), nums.end()));

	}
	template<typename BidrectionalIterator>
	bool next_permutation(BidrectionalIterator first,
		BidrectionalIterator last)
	{
		const auto rbegin = reverse_iterator<BidrectionalIterator>(last);
		const auto rend = reverse_iterator<BidrectionalIterator>(first);
		//second
		auto pivot = next(rbegin);
		while (pivot != rend && !(*pivot < *prev(pivot)))
		{
			++pivot;
		}
		if (pivot == rend)
		{
			reverse(rbegin, rend);
			return false;
		}
		auto change = find_if(rbegin, pivot, bind1st(less<int>(), *pivot));
		swap(*pivot, *change);
		reverse(rbegin, pivot);
		return true;
	}
};
int main()
{
	Solution s;
	int a[] = {5,1,1};
	vector<int> ss(a, a + 3);
	int count = 1;
	//for_each(ss.begin(), ss.end(), [&count](int& x){ x = count++;});
	s.nextPermutation(ss);

	return 0;
}