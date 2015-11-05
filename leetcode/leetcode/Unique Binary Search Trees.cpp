#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <unordered_map>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	int numTrees(int n) {
		vector<int> data(n + 1, -1);
		data[0] = 1;
		data[1] = 1;
		return getNum(n, data);
	}
	int getNum(int x,vector<int>& data)
	{
		if (data[x] != -1)
		{
			return data[x];
		}
		else
		{
			int sum = 0;
			for (int i = 0; i <= x-1; ++i)
			{
				sum += getNum(i,data) * getNum(x - i - 1, data);
			}
			data[x] = sum;
			return data[x];
		}
	}

	vector<TreeNode*> generateTrees(int n) {
		
		if (n == 0)
		{
			return generate(1,0);
		}
		else 
			return generate(1,n);
	}
	vector<TreeNode*> generate(int begin, int end)
	{
		vector<TreeNode*> res;
		if (begin > end)
		{
			res.push_back(nullptr);
			return res;
		}
		for (int k = begin; k <= end; ++k)
		{
			vector<TreeNode*> left = generate(begin, k-1);
			vector<TreeNode*> right = generate(k + 1, end);
			for (auto i:left)
			{
				for (auto j:right)
				{
					TreeNode* root = new TreeNode(k);
					root->left = i;
					root->right = j;
					res.push_back(root);
				}
			}
		}
		return res;
	}
	/*bool isValidBST(TreeNode* root) {
		vector<int> res;
		inorder(root, res);
		if (res.size() <= 1)
		{
			return true;
		}
		for (int i = 1; i < res.size(); ++i)
		{
			if (res[i - 1] >= res[i])
			{
				return false;
			}
		}
		return true;
	}
	void inorder(TreeNode* root, vector<int>& res)
	{
		if (root == NULL)
		{
			return;
		}
		if (root->left !=NULL)
		{
			inorder(root->left, res);
		}
		res.push_back(root->val);
		if (root->right != NULL)
		{
			inorder(root->right, res);
		}
	}*/
	bool isValidBST(TreeNode* root) {
		return isValidBST(root, INT_MIN, INT_MAX);
	}
	bool isValidBST(TreeNode* root, int lower, int upper)
	{
		if (root == nullptr)
		{
			return true;
		}
		return root->val > lower && root->val < upper &&
			isValidBST(root->left, lower, root->val) &&
			isValidBST(root->right, root->val, upper);
	}
};
int main()
{
	Solution s;
	return 0;
}