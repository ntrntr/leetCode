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
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	int rob(TreeNode* root) {
		if (root == NULL)
			return 0;
		queue<TreeNode*> cur, tmp;
		cur.push(root);
		int odd = 0, even = 0;
		int flag = false;
		while (!cur.empty())
		{
			while (!cur.empty())
			{
				TreeNode* tt = cur.front();
				cur.pop();
				if (!flag)
				{
					odd += tt->val;
				}
				else
				{
					even += tt->val;
				}
				if (tt->left != NULL)
				{
					tmp.push(tt->left);
				}
				if (tt->right != NULL)
				{
					tmp.push(tt->right);
				}
			}
			flag = !flag;
			swap(cur, tmp);
		}
		return max(odd, even);
	}
};
int main()
{
	Solution s;
	queue<int> a;
	a.push(1);
	a.push(5);
	a.push(10);
	cout << a.front() << endl;;
	a.pop();
	cout << a.front() << endl;;
	a.pop(); cout << a.front() << endl;;
	a.pop();
	return 0;
}