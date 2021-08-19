/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		vector<TreeNode*> cur;
		vector<TreeNode*> p_path;
		vector<TreeNode*> q_path;
		getPath(root, p, q, cur, p_path, q_path);
		TreeNode* ret = p_path[0];
		auto size_p = p_path.size();
		auto size_q = q_path.size();
		for (int i = 0; i < min(size_p, size_q); ++i)
		{
			if (p_path[i] != q_path[i])
			{
				break;
			}
			else
			{
				ret = p_path[i];
			}
		}
		return ret;
	}

	void getPath(TreeNode* root, TreeNode* p, TreeNode* q, vector<TreeNode*>& cur, vector<TreeNode*>& p_path, vector<TreeNode*>& q_path)
	{
		cur.emplace_back(root);
		if (p_path.size() == 0 && root == p)
		{
			for (auto it = cur.begin(); it != cur.end(); ++it)
			{
				p_path.emplace_back(*it);
			}
		}
		if (q_path.size() == 0 && root == q)
		{
			for (auto it = cur.begin(); it != cur.end(); ++it)
			{
				q_path.emplace_back(*it);
			}
		}


		if (p_path.size() > 0 && q_path.size() > 0)
		{
			return;
		}

		if (root->left != nullptr)
		{
			getPath(root->left, p, q, cur, p_path, q_path);
		}
		if (root->right != nullptr)
		{
			getPath(root->right, p, q, cur, p_path, q_path);
		}
		cur.pop_back();
	}
};