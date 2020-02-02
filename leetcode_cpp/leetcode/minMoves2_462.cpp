

#include <vector>
#include <algorithm>
#include <complex>

class Solution {
public:
	long do_work(std::vector<int>& nums, long target)
	{
		long ret = 0;
		for (int num : nums)
		{
			ret += target > num ? (long)target - (long)num : (long)num - (long)target;
		}
		return ret;
	}

	long do_work1(std::vector<int>& nums, long target, long sum, long inc)
	{

		bool flag = true;
		target = target + inc;
		do
		{
			long upperValue = do_work(nums, target);
			if (upperValue < sum)
			{
				sum = upperValue;
				target = target + inc;
			}
			else
			{
				flag = false;
			}
		}
		while (flag);
		return sum;
	}

	int minMoves2(std::vector<int>& nums) {
		long sum = 0;
		sort(nums.begin(), nums.end());
		long mid = nums[nums.size() / 2];
		for (long num : nums)
		{
			sum += std::abs(num - mid);
		}

		return sum;
	}
};

int main(int argc, char* argv[])
{
	Solution s;
	_ASSERTE(s.minMoves2(std::vector<int>{ 1,2,3 }) == 2);
	_ASSERTE(s.minMoves2(std::vector<int>{ 1,2,4 }) == 3);
	_ASSERTE(s.minMoves2(std::vector<int>{ 1,0,0,6,8 }) == 14);
	_ASSERTE(s.minMoves2(std::vector<int>{ 203125577, -349566234, 230332704, 48321315, 66379082, 386516853, 50986744, -250908656, -425653504, -212123143 }) == 2127271182);
	return 0;
}
