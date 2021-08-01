#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.begin() + k -1, nums.end(), [](int left, int right){
            return left>right;
        });
        return nums[k-1];
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