#include <vector>
#include<algorithm>
using namespace std;

class sort_data
{
public:
    sort_data(int val, int orgion_index):val(val),orgion_index(orgion_index)
    {
        
    }
    int val;
    int orgion_index;
};

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> ret;
        auto ilen = intervals.size();
        vector<sort_data> new_data;
        for(auto i = 0; i < ilen; ++i)
        {
            new_data.push_back(sort_data(intervals[i][0], i));
        }
        sort(new_data.begin(), new_data.end(), [](const sort_data& a, const sort_data& b){
            return a.val < b.val;
        });
        auto tmp = sort_data(0,-1);
        for(auto i = 0; i < ilen; ++i)
        {
            auto end_val = intervals[i][1];
            tmp.val = end_val;
            auto iter = lower_bound(new_data.begin(), new_data.end(), tmp, [](const sort_data& a, const sort_data& b){
                return a.val < b.val;
            });
        
            if(iter == new_data.end())
            {
                ret.push_back(-1);
            }
            else
            {
                ret.push_back((*iter).orgion_index);
            }
        }
        return ret;
    }
};

int main(void)
{
    return 0;
}