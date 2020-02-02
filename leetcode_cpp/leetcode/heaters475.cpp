#include <vector>
#include <algorithm>
using namespace std;

//
// class Solution {
// private:
//
// 	
// public:
// 	static bool LessComp(int lhs, int rhs)
// 	{
// 		return lhs < rhs;
// 	}
// 	int findRadius(vector<int>& houses, vector<int>& heaters) {
// 		int ret = 0;
// 		std::sort(houses.begin(), houses.end(), LessComp);
// 		std::sort(heaters.begin(), heaters.end(), LessComp);
// 		std::vector<int>::iterator up, before;
// 		for(int i = 0; i < houses.size(); ++i)
// 		{
// 			 up = std::lower_bound(heaters.begin(), heaters.end(), houses[i]);
// 			if (up == heaters.end())
// 			{
// 				up = heaters.end() - 1;
// 			}
// 			if (up == heaters.begin())
// 			{
// 				before = up;
// 			}
// 			else
// 			{
// 				before = up - 1;
// 			}
// 			ret = max(ret, min(abs(*before - houses[i]), abs(*up - houses[i])));
//
// 		}
//
// 		return ret;
// 	}
// };

class Solution {
public:
	int findRadius(vector<int>& houses, vector<int>& heaters) {
		sort(houses.begin(), houses.end());
		sort(heaters.begin(), heaters.end());
		vector<int> res(houses.size(), INT_MAX);

		//rhs
		for (int i = 0, h = 0; i < houses.size() && h < heaters.size();)
		{
			if (houses[i] <= heaters[h])
			{
				res[i] = heaters[h] - houses[i];
				i++;
			}
			else
			{
				h++;
			}
		}
		//lhs
		for (int i = houses.size() - 1, h = heaters.size() - 1; i >= 0 && h >= 0;)
		{
			if (houses[i] >= heaters[h])
			{
				res[i] = min(res[i], houses[i] - heaters[h]);
				i--;
			}
			else
			{
				h--;
			}
		}

		return *std::max_element(res.begin(), res.end());
	}
};

void do_work()
{
	Solution s;
	vector<int> l1{ 1,2,3 };
	vector<int> l2{ 2 };

	_ASSERT(s.findRadius(l1, l2) == 1);
}

void do_work1()
{
	Solution s;
	vector<int> l1{ 1,2,3,4 };
	vector<int> l2{ 1,4 };

	_ASSERT(s.findRadius(l1, l2) == 1);
}

int main(int argc, char* argv[])
{
	do_work();
	do_work1();
	return 0;
}
