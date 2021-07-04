#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int> > map;
        for(auto i=0; i < nums.size(); i++)
        {
            if(map.find(nums[i]) == map.end())
            {
                map[nums[i]] = {i};
            }
            else
            {
                map[nums[i]].push_back(i);
            }
            if(map.find(target-nums[i]) != map.end())
            {
                auto index_list = map[target-nums[i]];
                if((target - nums[i]) != nums[i])
                {
                    return vector<int>{i, index_list[0]};
                }
                else if (index_list.size() >= 2)
                {
                    return vector<int>{index_list[0], index_list[1]};
                }
            }
            
        }
        return vector<int>{};
        
    }
};

int main(void)
{
    auto s = Solution();
    // vector<int> c = {2,7,11,15};
    // auto ret = s.twoSum(c, 9);
    vector<int> c = {3,3};
    auto ret = s.twoSum(c, 6);
    for(auto x:ret)
    {
        cout << x << endl;
    }
    return 0;
}