#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // nth_element(nums.begin(), nums.begin() + k -1, nums.end(), [](int left, int right){
        //     return left>right;
        // });
        nth_element2(nums, 0, nums.size()-1, k-1);
        return nums[k-1];
    }

    void print_vector(vector<int>& nums)
    {
		return;
        for(auto it = nums.begin(); it != nums.end(); ++it)
        {
            cout << *it << ",";
        }
        cout << endl;
    }

    void nth_element2(vector<int>& nums, int begin, int end,int k)
    {
        auto _begin = begin;
        auto _end = end;
        auto povit = nums[begin];
        while(begin < end)
        {
            cout << "init:" << povit << endl;
            print_vector(nums);
            while (begin < end)
            {
                if (nums[end] > povit)
                {
                    nums[begin] = nums[end];
                    begin++;
                    end;
                    break;
                }
                else
                {
                    end--;
                    continue;
                }
            }
            cout << "last sort\tbegin:" << begin << ",end:"<< end<<endl;
            print_vector(nums);
            while (begin < end)
            {
                if (nums[begin] <= povit)
                {
                    nums[end] = nums[begin];
                    end--;
                    break;
                }
                else
                {
                    begin++;
                    continue;
                }
            }
            cout << "before sort\tbegin:" << begin << ",end:"<< end<<endl;
            print_vector(nums);
            
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