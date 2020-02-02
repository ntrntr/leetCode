#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <unordered_map>
using namespace std;
struct TreeLinkNode {
	int val;
	TreeLinkNode *left;
	TreeLinkNode *right;
	TreeLinkNode *next;
	TreeLinkNode(int x):val(x),left(NULL),right(NULL),next(NULL){}
};
class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (root == NULL)
		{
			return;
		}
		queue<TreeLinkNode*> cur,pre;
		cur.push(root);
		while (!cur.empty())
		{
			while(!cur.empty())
			{
				TreeLinkNode* tmp = cur.front();
				cur.pop();
				if (tmp->left != NULL)
				{
					pre.push(tmp->left);
				}
				if (tmp->right != NULL)
				{
					pre.push(tmp->right);
				}
				if (!cur.empty())
				{
					tmp->next = cur.front();
				}
				else
				{
					tmp->next = NULL;
				}
			}
			swap(cur, pre);
		}
	}

};
int main()
{
	Solution s;
	return 0;
}