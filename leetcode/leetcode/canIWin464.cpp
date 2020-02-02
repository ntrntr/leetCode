#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger >= desiredTotal)
        {
        	return true;
        }
        if (maxChoosableInteger * (1 + maxChoosableInteger) / 2 < desiredTotal)
        {
        	return false;
        }
        dp = std::vector<int >(1 << desiredTotal, -1);
        int status = (1 << maxChoosableInteger) - 1;
        return miniMax(status, desiredTotal, maxChoosableInteger);
    }
private:
	std::vector<int > dp;

	bool miniMax(int status, int target, int maxChoosableInteger)
	{
		if (dp[status] != -1)
		{
			return dp[status];
		}
		for (int i = maxChoosableInteger; i >= 1; --i)
		{
			if (status & (1 << (i - 1)))
			{
				if (i >= target || !miniMax(status ^ (1 << (i - 1)), target - i, maxChoosableInteger))
				{
					dp[status] = 1;
					return true;
				}
			}
		}
		dp[status] = 0;
		return false;
	}
};

int main()
{
	cout << "hello world" << endl;
	return 0;
}