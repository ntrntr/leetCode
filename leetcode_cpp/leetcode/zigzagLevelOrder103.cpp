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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> ret;
		if (root == nullptr)
		{
			return ret;
		}
		vector<TreeNode*> cur, next;
		cur.push_back(root);
		bool is_left_to_right = false;
		while (cur.size() > 0)
		{
			is_left_to_right = !is_left_to_right;
			vector<int> tmp_val;
			auto ss = cur.size();
			for (int i = cur.size() - 1; i >= 0; --i)
			{
				tmp_val.push_back(cur[i]->val);
				if (is_left_to_right)
				{
					if (cur[i]->left != nullptr)
					{
						next.push_back(cur[i]->left);
					}
					if (cur[i]->right != nullptr)
					{
						next.push_back(cur[i]->right);
					}
				}
				else
				{
					if (cur[i]->right != nullptr)
					{
						next.push_back(cur[i]->right);
					}
					if (cur[i]->left != nullptr)
					{
						next.push_back(cur[i]->left);
					}
				}

			}
			cur.clear();
			swap(cur, next);
			ret.push_back(move(tmp_val));
		}
		return ret;
	}
};