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
	int getMinimumDifference(TreeNode* root) {
		vector<int> values;
		traverse(root, values);
		sort(values.begin(), values.end());
		auto min_ret = values[1] - values[0];
		for (auto i = 1; i < values.size(); ++i)
		{
			min_ret = min(min_ret, values[i] - values[i - 1]);
		}
		return min_ret;
	}

	void traverse(TreeNode* root, vector<int>& values)
	{
		if (root == nullptr)
		{
			return;
		}
		values.push_back(root->val);
		traverse(root->left, values);
		traverse(root->right, values);
	}
};