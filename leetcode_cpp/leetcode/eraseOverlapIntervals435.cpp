#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int> >& intervals) {
        auto total_len = intervals.size();
        if(total_len <= 1)
        {
            return 0;
        }
        sort(intervals.begin(), intervals.end(), [](const vector<int>& left, const vector<int>& right)
        {
            return left[1] < right[1];
        });
        auto count = 1;
        auto end_val = intervals[0][1];
        for (int i = 1; i < total_len; i++)
        {
            if (intervals[i][0] >= end_val){
                end_val = intervals[i][1];
                count += 1;
            }
        }
        return total_len - count;
    }
};

int main(void)
{
    auto x = Solution();
    vector<vector<int>> list = {{1,2},{2,3}, {-1,9}, {5,9}, {2,3}, {2, 5}};
    auto ret = x.eraseOverlapIntervals(list);
    cout << ret << endl;
    return 0;
}