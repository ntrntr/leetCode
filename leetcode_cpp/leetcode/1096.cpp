#include <vector>
#include <iostream>
using namespace std;
void dfs(int cur, int cursum, vector<int>& path, vector<vector<int> >& res, int n)
{
	if (cursum > n)
	{
		return;
	}
	if (cursum == n)
	{
		res.push_back(path);
		return;
	}
	for (int i = cur; i <= n; i++)
	{
		//bu chen
		dfs(i + 1, cursum, path, res, n);
		//chen
		path.push_back(i);
		dfs(i, cursum * i, path, res, n);
		path.pop_back();
	}
}
int main()
{
	int n;
	cin>>n;
	vector<vector<int> > res;
	vector<int> path;	
	dfs(1, 1, path, res, n);
	for (auto i:res)
	{
		for(auto j:i)
		{
			cout<<j<<" "; 
		}
		cout<<endl;
	}
	return 0;
}