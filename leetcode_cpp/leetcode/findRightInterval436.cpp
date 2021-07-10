#include <vector>
#include<algorithm>
#include<map>
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

class Solution1 {
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

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int, int> hash;
        auto ilen = intervals.size();
        for(auto i=0; i < ilen; ++i)
        {
            hash[intervals[i][0]] = i;
        }
        vector<int> res;
        for(auto i=0; i < ilen; ++i)
        {
            auto it = hash.lower_bound(intervals[i][1]);
            if(it == hash.end())
            {
                res.push_back(-1);
            }
            else
            {
                res.push_back(it->second);
            }
        }
        return res;
    }
};

int main(void)
{
    return 0;
}