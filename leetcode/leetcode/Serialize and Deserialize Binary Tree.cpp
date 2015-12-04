#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <unordered_map>
#include <sstream>
#include <stdio.h>
#include <queue>
#include <deque>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Codec {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
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
	}
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
		vector<int> res;
		preorder(root, res);
		inorder(root, res);
		string s;
		char* sss = new char[256];
		for (auto it = res.begin(); it != res.end(); ++it)
		{
			sprintf(sss,"%d",*it);
			//itoa(*it, sss, 10);
			s += sss;
			if (it != res.end() - 1)
			{
				s += ",";
			}
		}
		delete[] sss;
		//cout<<s;
		return s;
		
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> res;
		string::iterator it;
		string::iterator begin = data.begin();
		
		while (true)
		{
			it = find(begin, data.end(),',');
			if (it != data.end())
			{
				string tmp(begin, it);
				res.push_back(atoi(tmp.c_str()));
			}
			else
			{
				string tmp(begin, it);
				res.push_back(atoi(tmp.c_str()));
				break;
			}
			begin = next(it);
		}

		return buildTree(res.begin(), next(res.begin(),res.size()/2), next(res.begin(),res.size()/2), res.end());
    }
	void preorder(TreeNode* root, vector<int>& res)
	{
		if (root == NULL)
		{
			return;
		}
		res.push_back(root->val);
		preorder(root->left, res);
		preorder(root->right, res);
	}
	void inorder(TreeNode* root, vector<int>& res)
	{
		if (root == NULL)
		{
			return ;
		}
		inorder(root->left, res);
		res.push_back(root->val);
		inorder(root->right, res);
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
int main()
{
	TreeNode* tl,*tr,*node;
	TreeNode root(1);
	tl = root.left = new TreeNode(6);
	tr = root.right = new TreeNode(2);
	node = tl->left = new TreeNode(7);
	tl->right = new TreeNode(5);
	node->left = new TreeNode(8);
	node->left->left = new TreeNode(7);
	node->left->right = new TreeNode(9);
	//root.right = new TreeNode(1);
	//root.right->right = new TreeNode(1115);
	Codec s;
	TreeNode* tmp = s.deserialize(s.serialize(&root));
	deque<TreeNode*> myqueue,tmpq;
	myqueue.push_back(tmp);
	while (!myqueue.empty())
	{
		while(!myqueue.empty())
		{
			TreeNode* t = myqueue.front();
			cout<<t->val<<" ";
			myqueue.pop_front();
			if (t->left != NULL)
			{
				tmpq.push_back(t->left);
			}
			if (t->right != NULL)
			{
				tmpq.push_back(t->right);
			}
		}
		cout<<endl;
		swap(myqueue, tmpq);
	}
	return 0;
}