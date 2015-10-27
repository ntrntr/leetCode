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
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		const int n = gas.size();
		vector<int> f(n);
		int sum = 0;
		int maxPos, minPos, maxData = INT_MIN, minData = INT_MAX;
		for(int i = 0; i < n; ++i)
		{
			f[i] = gas[i] - cost[i];
			if (maxData < f[i])
			{
				maxData = f[i];
				maxPos = i;
			}
			if (minData > f[i])
			{
				minData = f[i];
				minPos = i;
			}
			sum += f[i];
		}
		if(sum < 0)
			return -1;
		else
			return maxPos;

	}
};
int main()
{
	Solution s;
	int a[] = {1,2,3,3};
	int b[] = {2,1,5,1};
	vector<int> gas(a, a + 4);
	vector<int> cost(b, b + 4);
	cout<<s.canCompleteCircuit(gas, cost);
	return 0;
}