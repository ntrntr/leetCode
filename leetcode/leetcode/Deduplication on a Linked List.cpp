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
struct node
{
	node(){};
	node(int a, int b, int c) :address(a), value(b), next(c){};
	int address;
	int value;
	int next;
};
int main()
{
	int start, n;
	cin >> start >> n;
	int a, b, c;
	map<int, int> link;
	map<int, int> keyvalue;
	for (int i = 0; i < n; ++i)
	{
		cin >> a >> b >> c;
		link[a] = c;
		keyvalue[a] = b;
	}
	vector<int> f1, f2;
	map<int, int> visit;
	int i = start;
	do 
	{
		if (visit[abs(keyvalue[i])] == 0)
		{
			f1.push_back(i);
			++visit[abs(keyvalue[i])];
		}
		else
		{
			f2.push_back(i);
		}
		i = link[i];
	} while (i != -1);
	for (int i = 0; i < f1.size(); ++i)
	{
		if (i == f1.size() - 1)
		{
			printf("%05d %d -1\n", f1[i], keyvalue[f1[i]]);
		}
		else
		{
			printf("%05d %d %05d\n", f1[i], keyvalue[f1[i]], f1[i+1]);
		}
	}
	for (int i = 0; i < f2.size(); ++i)
	{
		if (i == f2.size() - 1)
		{
			printf("%05d %d -1\n", f2[i], keyvalue[f2[i]]);
		}
		else
		{
			printf("%05d %d %05d\n", f2[i], keyvalue[f2[i]], f2[i + 1]);
		}
	}
	return 0;
}