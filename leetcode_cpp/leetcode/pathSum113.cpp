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
	vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
		vector<vector<int>> res;
		vector<int> path;
		if (root != nullptr)
		{
			dfs(root, 0, targetSum, path, res);
		}
		return res;
	}

	void dfs(TreeNode* cur, int current_sum, int targetSum, vector<int>& path, vector<vector<int>>& res)
	{
		current_sum = current_sum + cur->val;
		path.push_back(cur->val);
		if (current_sum == targetSum && cur->left == nullptr && cur->right == nullptr)
		{
			res.push_back(path);
		}
		else
		{
			if (cur->left != nullptr)
			{
				dfs(cur->left, current_sum, targetSum, path, res);
			}
			if (cur->right != nullptr)
			{
				dfs(cur->right, current_sum, targetSum, path, res);
			}
		}
		path.pop_back();
	}
};