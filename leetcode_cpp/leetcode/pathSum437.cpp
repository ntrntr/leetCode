
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
	void getTreeNodes(TreeNode* root, vector<TreeNode*>& tlist)
	{
		if (root == nullptr)
		{
			return;
		}
		tlist.push_back(root);
		getTreeNodes(root->left, tlist);
		getTreeNodes(root->right, tlist);
	}

	int getSumByStart(TreeNode* root, int targetSum, int current_value)
	{
		if(root == nullptr)
		{
			return 0;
		}
		auto ret = 0;
		if (current_value + root->val == targetSum)
		{
			ret += 1;
		}
		ret += getSumByStart(root->left, targetSum, current_value + root->val);
		ret += getSumByStart(root->right, targetSum, current_value + root->val);
		return ret;
	}
	
	int pathSum(TreeNode* root, int targetSum) {
		if(root == nullptr)
		{
			return 0;
		}
		vector<TreeNode*> tlist;
		getTreeNodes(root, tlist);
		auto ret = 0;
		for(auto* t:tlist)
		{
			ret += getSumByStart(t, targetSum, 0);
		}
		return ret;
		
	}
};

int main(void)
{
	return 0;
}