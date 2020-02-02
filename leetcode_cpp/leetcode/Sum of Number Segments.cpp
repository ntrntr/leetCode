#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <unordered_map>
using namespace std;
class Solution
{
public:
	Solution();
	~Solution();
	double getres(vector<double>& f)
	{
		const int n = f.size();
		sum = 0;
		long int tmp1 = n;
		long int tmp2 = 1;
		for (int i = 0; i < n; ++i)
		{
			sum += f[i] * (tmp1-- * tmp2++);
		}

			
		return sum;
	}
	
private:
	double sum;
};

Solution::Solution()
{
}

Solution::~Solution()
{
}
int main()
{
	Solution s;
	vector<double> f;
	int n;
	cin >> n;
	double tmp;
	for (int i = 0; i < n; ++i)
	{
		cin >> tmp;
		f.push_back(tmp);
	}
	printf("%.2f\n", s.getres(f));
	return 0;
}