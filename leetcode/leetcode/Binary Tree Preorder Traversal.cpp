#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <unordered_map>
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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
		preorderTree(root, res);
		return res;
    }
	void preorderTree(TreeNode* root, vector<int>& res)
	{
		if (root == NULL)
		{
			return ;
		}
		res.push_back(root->val);
		preorderTree(root->left, res);
		preorderTree(root->right, res);
	}
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		inorderTree(root, res);
		return res;
	}
	void inorderTree(TreeNode* root, vector<int>& res)
	{
		if (root == NULL)
		{
			return ;
		}
		inorderTree(root->left, res);
		res.push_back(root->val);
		inorderTree(root->right, res);
	}
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> res;
		postorderTree(root, res);
		return res;
	}
	void postorderTree(TreeNode* root, vector<int>& res)
	{
		if (root == NULL)
		{
			return ;
		}
		postorderTree(root->left, res);
		postorderTree(root->right, res);
		res.push_back(root->val);
	}

	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (root == NULL)
		{
			return res;
		}
		vector<int> tmpRes;
		queue<TreeNode*> q,qtmp;
		q.push(root);
		bool flag = false;
		while (!q.empty())
		{
			tmpRes.clear();
			while(!q.empty())
			{
				TreeNode* tmp = q.front();
				q.pop();
				tmpRes.push_back(tmp->val);
				if (tmp->left != NULL)
				{
					qtmp.push(tmp->left);
				}
				if (tmp->right != NULL)
				{
					qtmp.push(tmp->right);
				}

			}
			swap(q, qtmp);
			if (flag)
			{
				reverse(tmpRes.begin(), tmpRes.end());
			}
			res.push_back(tmpRes);
			flag = !flag;

		}
		//reverse(res.begin(), res.end());
		return res;
	}
	void recoverTree(TreeNode* root) {
		vector<TreeNode*> res;
		vector<int> tmpInt;
		inorderTree(root, res);
		for (auto i:res)
		{
			tmpInt.push_back(i->val);
		}
		vector<int> tmp(tmpInt);
		sort(tmp.begin(), tmp.end());
		for (int i = 0; i < tmpInt.size(); ++i)
		{
			if (tmpInt[i] != tmp[i])
			{
				res[i]->val = tmp[i];
			}
		}
	}
	void inorderTree(TreeNode* root, vector<TreeNode*>& res)
	{
		if (root == NULL)
		{
			return ;
		}
		inorderTree(root->left, res);
		res.push_back(root);
		inorderTree(root->right, res);
	}
	bool isSymmetric(TreeNode* root) {
		TreeNode* left,*right;
		if (root == NULL)
		{
			return true;
		}
		left = root->left;
		right = root->right;
		return isSym(left, right);
		
	}
	bool isSym(TreeNode* left, TreeNode* right)
	{
		if (left == NULL && right == NULL)
		{
			return true;
		}
		if (!(left != NULL && right != NULL))
		{
			return false;
		}
		if (left->val != right->val)
		{
			return false;
		}
		return isSym(left->left, right->right) && isSym(left->right, right->left);
	}
	bool isBalanced(TreeNode* root) {
		return isBal(root);
	}
	bool isBal(TreeNode* root)
	{
		if (root == NULL)
		{
			return true;
		}
		if (abs(getDepth(root->left) - getDepth(root->right))>1)
		{
			return false;
		}
		return isBal(root->left) && isBal(root->right);

	}
	int getDepth(TreeNode* root)
	{
		if (root == NULL)
		{
			return 0;
		}
		return max(getDepth(root->left) + 1, getDepth(root->right) + 1);
	}
	void flatten(TreeNode* root) {
		if (root == NULL)
		{
			return;
		}
		vector<TreeNode*> res;
		preorder(root, res);
		for (int i = 0; i < res.size()-1; ++i)
		{
			res[i]->left = NULL;
			res[i]->right = res[i + 1];
		}
		return;
	}
	void preorder(TreeNode* root, vector<TreeNode*>& res)
	{
		if (root == NULL)
		{
			return ;
		}
		res.push_back(root);
		preorder(root->left, res);
		preorder(root->right, res);
	}
	
};
int main()
{
	Solution s;
	TreeNode root(0);
	root.left = new TreeNode(1);
	s.recoverTree(&root);
	return 0;
}