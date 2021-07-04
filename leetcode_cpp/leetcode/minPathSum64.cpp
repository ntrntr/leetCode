#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        auto row_count = grid.size();
        auto col_count = grid[0].size();
        vector<int> pre(row_count, grid[0][0]);
        for(int i = 1; i < row_count; i++)
        {
            pre[i] = pre[i-1] + grid[i][0];
        }
        for(auto j = 1; j < col_count; j++)
        {
            pre[0] = pre[0] + grid[0][j];
            for(auto i = 1; i < row_count; i++)
            {
                pre[i] = min(pre[i-1], pre[i]) + grid[i][j];
            }
        }
        return pre[row_count-1];
    }
};

int main(void)
{
    auto s = Solution();
    vector<vector<int>> data = {{1,3,1},{1,5,1},{4,2,1}};
    auto val = s.minPathSum(data);
    cout << val << endl;
    return 0;
}