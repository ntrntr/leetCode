#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int getEraseNum(const vector<vector<int> >& intervals, int start, int end)
    {
        cout << "getEraseNum" << start << "-" << end << endl;
        if(start >= end){
            return 0;
        }
        if (end - start == 1)
        {
            const auto& a = intervals[start];
            const auto& b = intervals[end];
            if(a[1] <= b[0])
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
        auto len = end - start + 1;
        auto ret = len - 1;
        cout << "dec" << ret << endl;
        for(auto s=start; s <= end; s++)
        {
            ret = min(ret, getEraseNum(intervals, start, s - 1) + getEraseNum(intervals, s+1, end));
            cout << ret << " - erase index " << s << " start " << start << " end " << end << endl;
        }
        return ret;
    }

    int eraseOverlapIntervals(vector<vector<int> >& intervals) {
        auto total_len = intervals.size();
        if(total_len <= 1)
        {
            return 0;
        }
        sort(intervals.begin(), intervals.end(), [](const vector<int>& left, const vector<int>& right)
        {
            if(left[0] < right[0])
            {
                return true;
            }
            else if(left[0] > right[0])
            {
                return false;
            }
            else{
                return left[1] < right[1];
            }
        });
        for (const auto& x:intervals)
        {
            cout << x[0] << " " << x[1] << endl;
        }
        const auto& before = intervals[0];
        vector<vector<int> > tmp = {before};
        auto cur_min = before[0];
        auto cur_max = before[1];
        auto ret = 0;
        for (auto i=1; i < total_len; i++)
        {
            const auto& cur = intervals[i];
            // bound
            if(cur[0] <= cur_min && cur_max <= cur[1])
            {
                ret += 1;
            }
            // not intersection
            else if(cur_max < cur[0])
            {
                ret += getEraseNum(tmp, 0, tmp.size() - 1);
                tmp.clear();
                tmp.push_back(cur);
            }
            else
            {
                cout << "push back" << cur[0] << "-" << cur[1] << endl;
                tmp.push_back(cur);
            }
        }
        ret += getEraseNum(tmp, 0, tmp.size() - 1);
        return ret;
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