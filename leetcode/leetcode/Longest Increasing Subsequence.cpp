#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <unordered_map>
using namespace std;
template<typename T>
void myprint(vector<T>& f)
{
	for (auto i : f)
	{
		cout << i << " ";
	}
	cout << endl;
}
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		const int n = nums.size();
		if (n <= 1)
		{
			return n;
		}
		vector<int> f(n, 1);
		f[0] = 1;
		int prevMax = 1;
		for (int i = 1; i < n; ++i)
		{
			for (int j = i - 1; j >= 0; --j)
			{
				if (nums[i] > nums[j])
				{
					f[i] = max(f[i],f[j] + 1);
					prevMax = max(prevMax, f[i]);
				}
			}
		}
		return prevMax;
	}
	int maxProduct(vector<string>& words) {
		sort(words.begin(), words.end(), [](string& s1, string& s2){return s1.length() > s2.length(); });
		for (int i = 0; i < words.size(); ++i)
		{
			sort(words[i].begin(), words[i].end());
		}
		myprint(words);
		res = 0;
		for (int i = 0; i < words.size(); ++i)
		{
			for (int j = i + 1; j < words.size(); ++j)
			{
				res = max(res, getCompare(words[i], words[j]));
			}
		}
		return res;
	}
	int getCompare(string& s1, string& s2)
	{
		if (res > s1.length() * s2.length())
		{
			return 0;
		}
		vector<char> f;
		set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), back_inserter(f));
		return f.size() == 0 ? s1.length() * s2.length() : 0;
	}
	int trailingZeroes(int n) {
		int res = 0;
		int last = 1;
		for (int i = 2; i <= n; ++i)
		{
			last = last * i;
			while (last % 10 == 0)
			{
				last /= 10;
				res++;
			}
			last %= 10;

		}
		return res;
	}
	int res;
};

int main()
{
	Solution s;
	/*vector<int> f{ 3, 5, 6, 2, 5, 4, 19, 5, 6, 7, 12 };
	f.erase(unique(f.begin(), f.end()), f.end());
	sort(f.begin(), f.end());
	vector<int> g{ 7, 5, 6 ,-1,10};
	sort(g.begin(), g.end());
	vector<int> k;
	set_intersection(f.begin(), f.end(), g.begin(), g.end(), back_inserter(k));
	myprint(k);
	vector<string> words{ "abcw", "baz", "foo", "bar", "xtfn", "abcdef" };
	s.maxProduct(words);*/
	//cout << s.lengthOfLIS(f) << endl;
	cout<<s.trailingZeroes(5)<<endl;
	return 0;
}