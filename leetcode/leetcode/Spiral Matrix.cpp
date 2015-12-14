#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <unordered_map>
#include <functional>
#include <math.h>
using namespace std;
class Solution
{
public:
	Solution();
	~Solution();
	vector<vector<int> > getMatrix(int m, int n, vector<int>& f)
	{
		vector<vector<int>> res(m, vector<int>(n, 0));
		int beginrow = 0, endrow = m - 1, begincol = 0, endcol = n - 1;
		int direction = 1;
		int count = 0;
		while (true)
		{
			//right
			if (direction == 1)
			{
				for (int i = begincol; i <= endcol; ++i)
				{
					res[beginrow][i] = f[count++];
				}
				++beginrow;
				if (beginrow > endrow)
				{
					break;
				}
				direction = 2;
			}
			//xia
			if (direction == 2)
			{
				for (int i = beginrow; i <= endrow; ++i)
				{
					res[i][endcol] = f[count++];
				}
				--endcol;
				if (begincol > endcol)
				{
					break;
				}
				direction = 3;
			}
			if (direction == 3)
			{
				for (int i = endcol; i >= begincol; --i)
				{
					res[endrow][i] = f[count++];
				}
				--endrow;
				if (beginrow > endrow)
				{
					break;
				}
				direction = 4;
			}
			//shang
			if (direction == 4)
			{
				for (int i = endrow; i >= beginrow; --i)
				{
					res[i][begincol] = f[count++];
				}
				++begincol;
				if (begincol > endcol)
				{
					break;
				}
				direction = 1;
			}
		}
		return res;
	}
	void myprintf(vector<vector<int>>& f)
	{
		const int m = f.size();
		const int n = f.front().size();
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (j == 0)
				{
					cout << f[i][j];
				}
				else
					cout << " " << f[i][j];
			}
			cout << endl;
		}
	}
private:

};

Solution::Solution()
{
}

Solution::~Solution()
{
}

int main()
{
	Solution s;
	int N;
	cin >> N;
	vector<int> f;
	int tmp;
	for (int i = 0; i < N; ++i)
	{
		cin >> tmp;
		f.push_back(tmp);
	}
	sort(f.begin(), f.end(), greater<int>());
	int m, n;
	m =ceil(pow(N, 0.5));
	while(N % m != 0)
	{
		m++;
	}
	n = N / m;
	vector<vector<int> > res = s.getMatrix(m, n, f);
	s.myprintf(res);
	return 0;
}