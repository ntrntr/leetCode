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
struct stu
{
	int id;
	int c, m, e;
	int a;
	vector<int> rank;
	stu(){};
	stu(int i, int j, int k, int idd) :c(i), m(j), e(k), a(1.0*(i + j + k) / 3.0), id(idd){};
};
int main()
{
	int n, m;
	int count;
	cin >> n >> m;
	vector<stu> data;
	int a, b, c, d;
	unordered_map<int, int> strtoid;
	vector<char> course{ 'A', 'C', 'M', 'E' };
	int id = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> a >> b >> c >> d;
		strtoid[a] = id;
		data.push_back(stu(b, c, d, id));
		id++;
	}
	sort(data.begin(), data.end(), [](stu& a, stu& b){ return a.a > b.a; });
	count = 2;
	data[0].rank.push_back(1);
	for (int i = 1; i < data.size(); ++i)
	{
		if (data[i - 1].a == data[i].a)
		{
			data[i].rank.push_back(data[i - 1].rank.back());
		}
		else
			data[i].rank.push_back(count);
		count++;
	}
	sort(data.begin(), data.end(), [](stu& a, stu& b){ return a.c > b.c; });
	count = 2;
	data[0].rank.push_back(1);
	for (int i = 1; i < data.size(); ++i)
	{
		if (data[i - 1].c == data[i].c)
		{
			data[i].rank.push_back(data[i - 1].rank.back());
		}
		else
			data[i].rank.push_back(count);
		count++;
	}
	sort(data.begin(), data.end(), [](stu& a, stu& b){ return a.m > b.m; });
	count = 2;
	data[0].rank.push_back(1);
	for (int i = 1; i < data.size(); ++i)
	{
		if (data[i - 1].m == data[i].m)
		{
			data[i].rank.push_back(data[i - 1].rank.back());
		}
		else
			data[i].rank.push_back(count);
		count++;
	}
	sort(data.begin(), data.end(), [](stu& a, stu& b){ return a.e > b.e; });
	count = 2;
	data[0].rank.push_back(1);
	for (int i = 1; i < data.size(); ++i)
	{
		if (data[i - 1].e == data[i].e)
		{
			data[i].rank.push_back(data[i - 1].rank.back());
		}
		else
			data[i].rank.push_back(count);
		count++;
	}
	sort(data.begin(), data.end(), [](stu& a, stu& b){ return a.id < b.id; });
	for (int i = 0; i < m; ++i)
	{
		cin >> a;
		if (strtoid.find(a) == strtoid.end())
		{
			cout << "N/A" << endl;
		}
		else
		{
			int id = strtoid[a];
			int rank = data[id].rank[0];
			int pos = 0;
			for (int j = 1; j < 4; ++j)
			{
				if (rank > data[id].rank[j])
				{
					pos = j;
					rank = data[id].rank[j];
				}
			}
			cout << rank << " " << course[pos] << endl;
		}
	}
	return 0;
}