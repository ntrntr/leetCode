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
	/*TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return buildTree(begin(preorder), end(preorder), begin(inorder), end(inorder));
	}
	template<typename InputIterator>
	TreeNode* buildTree(InputIterator pre_begin, InputIterator pre_end, InputIterator in_begin, InputIterator in_end)
	{
		if (pre_begin == pre_end)
		{
			return nullptr;
		}
		if (in_begin == in_end)
		{
			return nullptr;
		}
		auto root = new TreeNode(*pre_begin);

		auto inRootPos = find(in_begin, in_end, *pre_begin);
		auto leftsize = distance(in_begin, inRootPos);

		root->left = buildTree(next(pre_begin), next(pre_begin, leftsize + 1), in_begin, inRootPos);
		root->right = buildTree(next(pre_begin, leftsize + 1), pre_end, next(inRootPos),in_end);
		return root;
	}*/
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		return buildTree(begin(inorder), end(inorder), begin(postorder), end(postorder));
	}
	
	template<typename InputIterator>
	TreeNode* buildTree(InputIterator in_begin, InputIterator in_end, InputIterator post_begin, InputIterator post_end)
	{
		if (in_begin == in_end)
		{
			return nullptr;
		}
		if (post_begin == post_end)
		{
			return nullptr;
		}
		TreeNode* root = new TreeNode(*prev(post_end));
		auto inRootPos = find(in_begin, in_end, *prev(post_end));
		auto leftsize = distance(in_begin, inRootPos);
		root->left = buildTree(in_begin, next(in_begin, leftsize), post_begin, next(post_begin, leftsize));
		root->right = buildTree(next(inRootPos), in_end, next(post_begin, leftsize), prev(post_end));
	}
};
int main()
{
	Solution s;
	return 0;
}