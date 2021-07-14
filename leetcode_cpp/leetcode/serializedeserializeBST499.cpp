#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Codec1 {
public:
	void split(const string&s, vector<string>& tokens, const string& delimiters = ",")
	{
		auto lastPos = s.find_first_not_of(delimiters, 0);
		auto pos = s.find_first_of(delimiters, lastPos);
		while (pos != string::npos || lastPos != string::npos)
		{
			tokens.push_back(s.substr(lastPos, pos - lastPos));
			lastPos = s.find_first_not_of(delimiters, pos);
			pos = s.find_first_of(delimiters, lastPos);
		}
	}

	void _serialize(TreeNode* root, long index, stringstream& ss)
	{
		if (root != nullptr)
		{
			ss << long(index) << "," << root->val << ",";
			_serialize(root->left, index * 2, ss);
			_serialize(root->right, index * 2 + 1, ss);
		}
	}

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		stringstream ss;
		_serialize(root, 1, ss);
		return ss.str();
	}
	void linkNode(unordered_map<long, TreeNode*>& m, long root_index)
	{
		if (m.find(root_index) != m.end())
		{
			if (m.find(root_index * 2) != m.end())
			{
				m[root_index]->left = m[root_index * 2];
				linkNode(m, root_index * 2);
			}
			if (m.find(root_index * 2 + 1) != m.end())
			{
				m[root_index]->right = m[root_index * 2 + 1];
				linkNode(m, root_index * 2 + 1);
			}
		}
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		TreeNode* ret = nullptr;
		auto data_size = data.size();
		if (data_size > 0)
		{
			vector<string> tokens;
			split(data, tokens);
			unordered_map<long, TreeNode*> m;
			auto tokens_size = tokens.size();
			for (auto i = 0; i < tokens_size; )
			{
				auto index = stol(tokens[i]);
				auto val = stoi(tokens[i + 1]);
				TreeNode* tre = new TreeNode(val);
				m[index] = tre;
				i += 2;
			}
			linkNode(m, 1);
			ret = m[1];
		}
		return ret;
	}
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
	void _serialize(TreeNode* root, string&s)
	{
		if (root != nullptr)
		{
			char buffer[4];
			memcpy(buffer, &(root->val), sizeof(int));
			for (auto i = 0; i < 4; ++i)
			{
				s.push_back(buffer[i]);
			}
			_serialize(root->left, s);
			_serialize(root->right, s);
		}
	}

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		string s;
		_serialize(root, s);
		return s;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		int start_pos = 0;
		return construct(data, start_pos, INT_MIN, INT_MAX);
	}

	TreeNode* construct(const string&s, int& pos, int min_val, int max_val)
	{
		if (pos >= s.size())
		{
			return nullptr;
		}
		int value;
		memcpy(&value, &s[pos], sizeof(int));
		if (value < min_val || value > max_val)
		{
			return nullptr;
		}
		pos += sizeof(int);
		TreeNode* node = new TreeNode(value);
		node->left = construct(s, pos, min_val, value);
		node->right = construct(s, pos, value, max_val);
		return node;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;


// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;