#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:

	vector<vector<bool>> visit;
		bool searchMatrix(vector<vector<int>>& matrix, int target) {
			const int n = matrix.size();
			const int m = matrix[0].size();
			visit.resize(n, vector<bool>(m, false));
			return search(0,0, matrix, target);
		}
		bool search(int x, int y,vector<vector<int>>& matrix,int target)
		{
			if(x >= matrix.size() || y >= matrix[0].size() || matrix[x][y] > target) return false;
			if(matrix[x][y] == target)
			{
				return true;
			}
			

			if(matrix[x][y] < target)
			{
				return search(x+1, y, matrix,target) || search(x, y+1, matrix, target);
			}

		}

	/*template<typename ForwardIterator, typename T>
	ForwardIterator upper_bound(ForwardIterator first, ForwardIterator last, T value)
	{
		while (first != last)
		{
			auto mid = next(first, distance(first, last) / 2);
			if (*mid < value)
			{
				first = mid+1;
			}
			else
				last = mid;
		}
		return first;
	}
	template<typename ForwardIterator, typename T>
	ForwardIterator upper_bound(ForwardIterator first, ForwardIterator last, T value)
	{
		while (first != last)
		{
			auto mid = next(first, distance(first, last) / 2);
			if (*mid <= value)
			{
				first = mid+1;
			}
			else
				last = mid;
		}
		return first;
	}
	vector<int> searchRange(vector<int>& nums, int target) {
		
	}*/
	void search(int i, int j, vector<int>& nums, int target, vector<int>& res)
	{
		if(i > j)
			return ;
		int mid = (i + j) / 2;
		if(nums[mid] == target)
		{
			int tmp = mid;
			while(tmp - 1 >= i && nums[mid] == nums[tmp - 1])
			{
				tmp--;
			}
			res[0] = tmp;
			tmp = mid;
			while(tmp + 1 <= j && nums[mid] == nums[tmp + 1])
			{
				tmp++;
			}
			res[1] = tmp;
			return;
		}
		else if(nums[mid] > target)
		{
			search(i, mid-1, nums, target, res);
		}
		else if(nums[mid] < target)
		{
			search(mid + 1, j, nums, target, res);
		}
	}

};
int main()
{
	Solution s;
	vector<int> f(1,1);
//	s.searchRange(f, 0);
	return 0;
}