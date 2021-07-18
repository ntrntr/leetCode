class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int ret = 0;
        auto nums_size = nums.size();
        for(auto i = 0; i < nums_size -1; ++i)
        {
            auto current_value = static_cast<long long int>(nums[i]);
            for(auto j = i + 1; j < nums_size; ++j)
            {
                if (current_value > 2 * static_cast<long long int>(nums[j]))
                {
                    ret += 1;
                }
            }
        }
        return ret;
    }
};