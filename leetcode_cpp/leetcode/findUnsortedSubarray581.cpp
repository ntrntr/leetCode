class Solution {
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