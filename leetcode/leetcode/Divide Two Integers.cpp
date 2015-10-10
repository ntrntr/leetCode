#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
class Solution {
public:
	int divide(int dividend, int divisor) {
		/*if(divisor == 0)
			return INT_MAX;
		if (dividend == INT_MIN && divisor == -1)
		{
			return INT_MAX;
		}
		return dividend / divisor;*/

		long long a = dividend >= 0 ? dividend:-(long long)dividend;
		long long b = divisor >= 0? divisor: -(long long )divisor;
		long long result = 0;
		while(a >= b)
		{
			long long c = b;
			for (int i = 0; a >= c; ++i, c = c << 1) //*2
			{
				a = a - c;
				result = result + 1 << i;
			}
		}
		return ((dividend^divisor)>>31) ? (-result): result;
	}
};
int main()
{
	return 0;
}