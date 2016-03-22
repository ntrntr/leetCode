#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <string.h>
using namespace std;
struct node
{
	int val;
	int left;
	int right;
	node(){}
	node(int a, int b, int c):val(a), left(b), right(c)
	{
	}

};
void getLNR(int root, vector<int>& res, vector<node>& nodes)
{
	if (nodes[root].left != -1)
	{
		getLNR(nodes[root].left, res, nodes);
	}
	res.push_back(root);
	if (nodes[root].right != -1)
	{
		getLNR(nodes[root].right, res, nodes);
	}
}
int main1()
{
	int n;
	cin>>n;
	vector<node> nodes(n);
	vector<int> father(n);
	for (int i = 0; i < n; ++i)
	{
		father[i] = i;
	}
	char a[5];
	char b[5];
	int left,right;
	for (int i = 0; i < n; ++i)
	{
		
		cin>>a>>b;
		if (strcmp(a, "-") == 0)
		{
			nodes[i].right = -1;
		}
		else
		{
			nodes[i].right = atoi(a);
			father[atoi(a)] = i;
		}

		if (strcmp(b, "-") == 0)
		{
			nodes[i].left = -1;
		}
		else
		{
			nodes[i].left = atoi(b);
			father[atoi(b)] = i;
		}
		
	}
	int tmp = 0,root;
	while (father[tmp] != tmp)
	{
		tmp = father[tmp];

	}
	root = tmp;
	vector<int> res;
	queue<int> cur,next;
	cur.push(tmp);
	while(!cur.empty())
	{
		while (!cur.empty())
		{
			int tmp = cur.front();
			res.push_back(tmp);
			cur.pop();
			if (nodes[tmp].left != -1)
			{
				next.push(nodes[tmp].left);
			}
			if (nodes[tmp].right != -1)
			{
				next.push(nodes[tmp].right);
			}
		}
		swap(cur, next);
		

	}
	for (int i = 0; i < n; ++i)
	{
		if (i == 0)
		{
			cout<<res[i];
		}
		else
		{
			cout<<" "<<res[i];
		}
	}
	//for (auto i:res)
	//{
	//	cout<<i<<" ";
	//}
	cout<<endl;
	//cout<<tmp<<endl;

	//lnr
	res.clear();
	getLNR(root, res, nodes);
	for (int i = 0; i < n; ++i)
	{
		if (i == 0)
		{
			cout<<res[i];
		}
		else
		{
			cout<<" "<<res[i];
		}
	}
	cout<<endl;
	return 0;
}
