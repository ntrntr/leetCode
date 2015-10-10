#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
class Solution {
public:
	bool search(vector<int>& nums, int target) {
		return nums.end() != find_if(nums.begin(), nums.end(), [target](int x){return x == target;});
	}
};
int main()
{
	return 0;
}