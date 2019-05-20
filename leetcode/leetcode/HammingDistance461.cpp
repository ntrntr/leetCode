#include <cstdlib>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
	int CountOne(int i)
	{
		int ret = 0;
		while (i)
		{
			i = i & (i - 1);
			ret++;
		}
		return ret;
	}

	int hammingDistance(int x, int y) {
		int c = x ^ y;
		return CountOne(c);
	}
};


int main(int argc, char* argv[])
{
	Solution s;
	_ASSERTE(s.hammingDistance(1, 4) == 2);
	_ASSERTE(s.hammingDistance(1, 1) == 0);
	return 0;
}
