#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <unordered_map>
#include <limits.h>
#include <queue>
using namespace std;
vector<int> postorder;
vector<int> inorder;
struct node
{
	int data;
	node* left;
	node* right;
	node(){};
	node(int n) :data(n), left(NULL), right(NULL){};
};
node* buildtree(int posti, int postj, int ini, int inj)
{
	if (posti > postj || ini > inj)
	{
		return NULL;
	}
	node* root = new node(postorder[postj]);
	int pos;
	for (int i = ini; i <= inj; ++i)
	{
		if (inorder[i] == postorder[postj])
		{
			pos = i;
			break;
		}
	}
	root->left = buildtree(posti, posti + pos - ini - 1, ini, pos - 1);
	root->right = buildtree(posti + pos - ini, postj - 1, pos + 1, inj);
	return root;
}
vector<int> order(node* root)
{
	vector<int> res;
	if (root == NULL)
	{
		return res;
	}
	queue<node*> p, q;
	p.push(root);
	while (!p.empty())
	{
		while (!p.empty())
		{
			node* tmp = p.front();
			p.pop();
			res.push_back(tmp->data);
			if (tmp->left != NULL)
			{
				q.push(tmp->left);
			}
			if (tmp->right != NULL)
			{
				q.push(tmp->right);
			}

		}
		swap(p, q);
	}
	return res;
}
int main()
{
	int n;
	cin >> n;
	postorder.resize(n);
	inorder.resize(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> postorder[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> inorder[i];
	}
	node* root = buildtree(0, n - 1, 0, n - 1);
	vector<int> f = order(root);
	for (int i = 0; i < f.size(); ++i)
	{
		if (i == 0)
		{
			cout << f[i];
		}
		else
			cout << " " << f[i];
	}
	return 0;
}