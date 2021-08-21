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
    bool isCompleteTree(TreeNode* root) {
        bool ret = true;
        if (root == nullptr || (root->left==nullptr && root->right==nullptr))
        {
            return true;
        }
        vector<TreeNode*> cur;
        vector<TreeNode*> next;
        cur.emplace_back(root);
        while(cur.size() > 0)
        {
            bool before_stop = false;
            for(int i = 0; i < cur.size(); ++i)
            {
                auto node = cur[i];
                if (before_stop && (node->left != nullptr || node->right!= nullptr))
                {
                    return false;
                }
                if (node->left != nullptr && node->right != nullptr)
                {
                    next.push_back(node->left);
                    next.push_back(node->right);
                }
                else if(node->left == nullptr && node->right != nullptr)
                {
                    return false;
                }
                else if(node->left != nullptr && node->right == nullptr)
                {
                    
                    before_stop=true;
                    next.push_back(node->left);
                }
                else
                {
                    before_stop = true;
                }
            }
            if(cur.size() * 2 == next.size())
            {
                cur.clear();
                swap(cur, next);
            }
            else
            {
                cur.clear();
                swap(cur, next);
                for(auto p:cur)
                {
                    if(p->left != nullptr || p->right != nullptr)
                    {
                        return false;
                    }
                }
            }
            
        }
        return true;
    }
};