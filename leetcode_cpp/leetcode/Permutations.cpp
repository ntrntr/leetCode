#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <unordered_map>
#include <limits.h>
using namespace std;
int GetCircles(vector<int>& data)
{
	const int size = data.size();
	vector<bool> isVistied(size, false);
	int res = 0;
	int cur = 0;
	int visitedCount = 0;
	while (visitedCount < size)
	{
		for (int i = cur; i < size; ++i)
		{
			if (isVistied[i] == false)
			{
				cur = i;
				break;
			}
		}
		isVistied[cur] = true;
		visitedCount++;
		res++;
		int tmp = cur;
		while (!isVistied[data[tmp] - 1])
		{
			isVistied[data[tmp] - 1] = true;
			tmp = data[tmp] - 1;
			visitedCount++;
		}
	}
	return res;
}
int main()
{
	int n;
	cin >> n;
	vector<int> data(n);
	int tmp;
	for (size_t i = 0; i < n; i++)
	{
		cin >> data[i];
	}
	cout << GetCircles(data) << endl;
	return 0;
}