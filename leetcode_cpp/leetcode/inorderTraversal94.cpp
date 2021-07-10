/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ret;
		_inorderTraversal(root, ret);
		return ret;
	}

	void _inorderTraversal(TreeNode* root, vector<int>& ret)
	{
		if (root)
		{
			if (root->left)
			{
				_inorderTraversal(root->left, ret);
			}
			ret.push_back(root->val);
			if (root->right)
			{
				_inorderTraversal(root->right, ret);
			}
		}
	}
};