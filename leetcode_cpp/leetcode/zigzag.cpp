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
class Zigzag
{
public:
	Zigzag();
	~Zigzag();
	void CreateZigzagMap(int n);
private:

};

Zigzag::Zigzag()
{
}

Zigzag::~Zigzag()
{
}

void Zigzag::CreateZigzagMap(int n)
{
	vector<vector<int>> data(n, vector<int>(n));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n - i; ++j)
		{
			int s = i + j;
			data[i][j] = s * (s + 1) / 2 + (s % 2 == 0 ? j : i);
		}
	}
	for (int i = n - 1; i > 0; --i)
	{
		for (int j = n - i; j < n; ++j)
		{
			data[i][j] = n * n - 1 - data[n - i - 1][n - j - 1];
		}
	}
	for (auto i:data)
	{
		for (auto j:i)
		{
			cout << j << " ";
		}
		cout << endl;
	}
}

int main()
{
	Zigzag s;
	s.CreateZigzagMap(10);
	return 0;
}