class Solution1 {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        auto copy_nums = vector<int>(nums);
        sort(copy_nums.begin(), copy_nums.end());
        auto total_size = nums.size();
        auto before = -1;
        auto end = total_size;
        auto i = 0;
        for(before=0;before < total_size; ++before)
        {
            if (copy_nums[before] != nums[before])
            {
                break;
            }
        }
        if(before == total_size)
        {
            return 0;
        }
        for(end=total_size -1; end >= 0; --end)
        {
            if (copy_nums[end] != nums[end])
            {
                break;
            }
        }
        return end - before + 1;
    }
};

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        auto end = -2;
        auto begin = -1;
        auto max_value = nums[0];
        auto size_len = nums.size();
        auto min_value = nums[size_len - 1];
        for(int i = 0; i < size_len; ++i)
        {
            max_value = max(max_value, nums[i]);
            min_value = min(min_value, nums[size_len - i - 1]);
            if (nums[i] < max_value)
            {
                end = i;
            }
            if (nums[size_len - i -1] > min_value)
            {
                begin = size_len - i -1;
            }
        }
        return end - begin + 1;
    }
};