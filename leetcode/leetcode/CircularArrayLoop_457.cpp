#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	bool CheckValid(int i,vector<int>& isValid, const vector<int>& vector)
	{
		bool isForward = vector[i] > 0;
		if ((i + vector[i]) % vector.size() == i)
		{
			isValid[i] = false;
		}
		else
		{
			isValid[i] = CheckValid((i + vector[i]) % vector.size(), isForward, i, isValid, vector);
		}
		return isValid[i] == 1;
	}

	int CheckValid(int i, bool isForward, int target, vector<int>& isValid, const vector<int>& vector)
	{

		if (i == target)
		{
			return 1;
		}
		if ((vector[i] > 0) == isForward && isValid[i] == 1)
		{
			isValid[i] = -1;
			isValid[i] = CheckValid((i + vector[i]) % vector.size(), isForward, target, isValid, vector);
			return isValid[i];
		}
		else
		{
			return 0;
		}
	}

	bool circularArrayLoop(std::vector<int>& nums) {
		bool ret = false;
		int len = nums.size();
		vector<int> isValid(len, 1);
		for (int i = 0; i < len; ++i)
		{
			if (isValid[i] == 0)
			{
				continue;
			}
			ret |= CheckValid(i, isValid,nums );
			if (ret)
			{
				break;
			}
		}
		return ret;
	}
};

int main()
{
	Solution mc;
	vector<int> test{ 2,-1,1,2,2 };
	_ASSERTE(mc.circularArrayLoop(test) == true);
	_ASSERTE(mc.circularArrayLoop(vector<int>{1,2}) == false);
	_ASSERTE(mc.circularArrayLoop(vector<int>{-2, 1, -1, -2, -2}) == false);
	_ASSERTE(mc.circularArrayLoop(vector<int>{2, 2, 2, 2, 2, 4, 7}) == false);
	_ASSERTE(mc.circularArrayLoop(vector<int>{1, 1, 2}) == false);
	_ASSERTE(mc.circularArrayLoop(vector<int>{-1,2}) == false);
	return 0;
}
