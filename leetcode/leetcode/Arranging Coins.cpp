#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

class ArrangingCoins
{
public:
	int arrangeCoins(int n) {
		long ret = (long)sqrt(2 * (float)n);
		while ((long)n < GetSum(ret))
		{
			ret--;
		}
		return ret;

	}

	long GetSum(long n)
	{
		return ((1 + n) * n) >> 1;
	}
};

int main()
{
	ArrangingCoins s;
	long currentSum = 0;
	long currentIndex = 0;
	for (int i = 1; i < INT_MAX; ++i)
	{
		if (currentSum + currentIndex + 1 == i)
		{
			currentSum += currentIndex + 1;
			currentIndex++;
		}

		_ASSERTE(s.arrangeCoins(i) == currentIndex);
	}
	return 0;
}

