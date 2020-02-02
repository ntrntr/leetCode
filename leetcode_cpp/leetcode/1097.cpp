#include <map>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
struct node
{
	int address;
	int value;
	int next;
	node(){}
	node(int a, int b,int c):address(a), value(b), next(c){}
};
int main()
{
	int root,n;
	cin>>root>>n;
	vector<int> key(10005,0);
	map<int, node> data;
	vector<int> res1,res2;
	int a,b,c;
	for (int i = 0; i < n; ++i)
	{
		cin>>a>>b>>c;
		data.insert(make_pair(a, node(a, b, c)));
	}
	int tmp = root;
	while (tmp != -1)
	{
		if (key[abs(data[tmp].value)] != 0)
		{
			res2.push_back(tmp);
			tmp = data[tmp].next;
		}
		else
		{
			++key[abs(data[tmp].value)];
			res1.push_back(tmp);
			tmp = data[tmp].next;
		}
	}
	for (int i = 0; i < res1.size(); i++)
	{
		if (i == res1.size() - 1)
		{
			printf("%05d %d -1\n",res1[i], data[res1[i]].value);
		}
		else
		printf("%05d %d %05d\n",res1[i], data[res1[i]].value, res1[i+1]);
	}
	for (int i = 0; i < res2.size(); i++)
	{
		if (i == res2.size() - 1)
		{
			printf("%05d %d -1\n",res2[i], data[res2[i]].value);
		}
		else
			printf("%05d %d %05d\n",res2[i], data[res2[i]].value, res2[i+1]);
	}
}