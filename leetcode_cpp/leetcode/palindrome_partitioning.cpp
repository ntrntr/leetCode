#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
class Solution {
public:
	int partition(string s) {
		const int n = s.size();
	vector<int> f(n + 1);
	for (int i = 0; i <= n; ++i)
	{
		f[i] = n - i - 1;
	}
	vector<vector<bool>	> p(n, vector<bool>(n, false));

	for (int i = n - 1; i >= 0; --i)
	{
		for (int j = i; j < n; ++j)
		{
			if (s[i] == s[j] && (j - i < 2 || p[i + 1][j - 1]))
			{
				p[i][j] = true;
				f[i] = min(f[i], f[j + 1] + 1);
			}

		}
	}
	return f[0];
	}
	

};

int main()
{
	Solution s;
	string ss;
	while (cin>>ss)
	{
		cout<<s.partition(ss)<<endl;
	}
	
	return 0;
}