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
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ret;
		if (root == nullptr)
		{
			return ret;
		}
		vector<TreeNode*> cur, next;
		cur.push_back(root);
		while (cur.size() > 0)
		{
			vector<int> tmp_val;
			for (int i = 0; i < cur.size(); ++i)
			{
				tmp_val.push_back(cur[i]->val);
				if (cur[i]->left != nullptr)
				{
					next.push_back(cur[i]->left);
				}
				if (cur[i]->right != nullptr)
				{
					next.push_back(cur[i]->right);
				}
			}
			cur.clear();
			swap(cur, next);
			ret.push_back(move(tmp_val));
		}
		return ret;
	}
};