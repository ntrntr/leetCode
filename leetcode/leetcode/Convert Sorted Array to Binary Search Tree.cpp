#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <unordered_map>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.size() == 0)
		{
			return nullptr;
		}
		return getNode(nums.begin(), nums.end());
	}
	template<typename InputIterator>
	TreeNode* getNode(InputIterator begin, InputIterator end)
	{
		if (begin == end)
		{
			return nullptr;
		}
		int dis = distance(begin, end);
		TreeNode* root = new TreeNode(*(begin + dis / 2));
		root->left = getNode(begin, (begin + dis / 2));
		root->right = getNode((begin + dis / 2 + 1),end);
		
	}
	TreeNode* sortedListToBST(ListNode* head) {
		vector<int> num;
		while(head)
		{
			num.push_back(head->val);
			head = head->next;
		}
		return sortedArrayToBST(num);
	}
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		//nums1.erase(nums1.begin() + m, nums1.end());
		//nums1.insert(nums1.end(), nums2.begin(),nums2.end());
		//sort(nums1.begin(), nums1.end());
		int ia = m - 1; 
		int ib = n - 1;
		int icur = n + m - 1;
		while (ia >= 0 && ib >= 0)
		{
			nums1[icur--] = nums1[ia] > nums2[ib] ? nums1[ia--]:nums2[ib--];
		}
		while (ib >= 0)
		{
			nums1[icur--] = nums2[ib--];

		}
	}
};
int main()
{
	Solution s;
	int a[] = {1,2,3};
	vector<int> nums(a, a+2);
	TreeNode* tmp = s.sortedArrayToBST(nums);
	return 0;
}