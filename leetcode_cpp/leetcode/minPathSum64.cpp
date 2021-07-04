#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        auto row_count = grid.size();
        auto col_count = grid[0].size();
        vector<int> row(col_count, 0);
        vector<int> col(col_count, 0);
        row[0] = grid[0][0];
        col[0] = grid[0][0];
        for(int i = 1; i < col_count; i++)
        {
            row[i] = grid[0][i] + row[i-1];
        }
        for(int i = 1; i < row_count; i++)
        {
            col[i] = grid[i][0]+ col[i-1];
        }
        for(auto i = 1; i < row_count; i++)
        {
            for(auto j = 1; j < col_count; j++)
            {
                row[j] = min(col[i], row[j-1]) + grid[i][j];
                col[i] = min(col[i-1], row[j]) + grid[i][j];
                // cout << "i:"<<i<<"\tj:"<<j<<"\t update val:" << tmp_data[i][j] << endl;
            }
        }
        // for(auto& c:tmp_data)
        // {
        //     for(auto j:c)
        //     {
        //         cout << j <<',';
        //     }
        //     cout << endl;
        // }
        return row[col_count-1];
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