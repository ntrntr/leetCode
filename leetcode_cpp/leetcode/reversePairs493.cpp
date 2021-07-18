#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution2 {
public:
    int reversePairs(vector<int>& nums) {
        int ret = 0;
        auto nums_size = nums.size();
        vector<int> data;
        data.push_back(nums[0]);
        for(auto i = 1; i < nums_size; ++i)
        {
            auto it = upper_bound(data.begin(), data.end(), nums[i] * 2);
            if (it != data.end())
            {
                ret += distance(it, data.end());
            }
            auto insert_it = lower_bound(data.begin(), data.end(), nums[i]);
            data.insert(insert_it, nums[i]);
        }
        return ret;
    }
};

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int ret = 0;
        auto nums_size = nums.size();
        vector<long long int> data;
        data.push_back(static_cast<long long int>(nums[0]));
        for(auto i = 1; i < nums_size; ++i)
        {
            auto it = upper_bound(data.begin(), data.end(), static_cast<long long int>(nums[i]) * 2);
            if (it != data.end())
            {
                ret += distance(it, data.end());
            }
            auto insert_it = lower_bound(data.begin(), data.end(), nums[i]);
            data.insert(insert_it, static_cast<long long int>(nums[i]));
        }
        return ret;
    }
};

int main(void)
{
    return 0;
}