#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // nth_element(nums.begin(), nums.begin() + k -1, nums.end(), [](int left, int right){
        //     return left>right;
        // });
        nth_element2(nums, 0, nums.size()-1, nums.size() - k-1);
        return nums[nums.size()-k-1];
    }

    void nth_element2(vector<int>& nums, int begin, int end,int k)
    {
        auto _begin = begin;
        auto _end = end;
        auto povit = nums[begin];
        while(begin < end)
        {
            while (begin < end)
            {
                if (nums[end] > povit)
                {
                    nums[begin] = nums[end];
                    begin++;
                    end--;
                    break;
                }
                else
                {
                    end--;
                    continue;
                }
            }
            while (begin < end)
            {
                if (nums[begin] <= povit)
                {
                    nums[end] = nums[begin];
                    end--;
                    begin++;
                    break;
                }
                else
                {
                    begin++;
                    continue;
                }
            }
            
        }
        nums[begin] = povit;
        if(begin == k)
        {
            return;
        }
        else if(begin < k)
        {
            nth_element2(nums, begin+1, _end, k);
        }
        else{
            nth_element2(nums, _begin, begin-1, k);
        }

    }
};

int main(void)
{
    auto s = Solution();
    vector<int> test = {-1,2,0};
    auto ret=s.findKthLargest(test, 3);
    cout << ret;
    return 0;
}