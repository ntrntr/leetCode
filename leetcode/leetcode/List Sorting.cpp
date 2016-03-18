#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <unordered_map>
#include <limits.h>
#include <stdio.h>
using namespace std;
struct cus
{
	string id;
	string name;
	int grade;
	cus(){};
	cus(string& a, string& b, int c) :id(a), name(b), grade(c){};
};
int main()
{
	int n, c;
	cin >> n >> c;
	vector<cus> f;
	string tmp1, tmp2;
	tmp1.resize(10);
	tmp2.resize(10);
	int tmp3;
	for (int i = 0; i < n; ++i)
	{
		//scanf("%s %s %d", &tmp1, &tmp2, &tmp3);
		cin >> tmp1 >> tmp2 >> tmp3;
		f.push_back(cus(tmp1, tmp2, tmp3));
	}
	if (c == 1)
	{
		sort(f.begin(), f.end(), [](cus& a, cus& b){
			return a.id < b.id;
		});
	}
	if (c == 2)
	{
		sort(f.begin(), f.end(), [](cus& a, cus& b)
		{
			if (a.name == b.name)
			{
				return a.id < b.id;
			}
			return a.name < b.name;
		});
	}
	if (c == 3)
	{
		sort(f.begin(), f.end(), [](cus& a, cus& b)
		{
			if (a.grade == b.grade)
			{
				return a.id < b.id;
			}
			return a.grade < b.grade;
		});
	}
	for (auto i:f)
	{
		printf("%s %s %d\n", i.id.c_str(), i.name.c_str(), i.grade);
		//cout << i.id << " " << i.name << " " << i.grade << endl;
	}
	return 0;
}