#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <unordered_map>
#include <limits.h>
using namespace std;
class NumArray {
public:
	vector<int> bit;
	vector<int> arr;
	int n;
	NumArray(vector<int> &nums) {
		n = nums.size();
		arr.assign(nums.begin(), nums.end());
		bit.assign(n + 1, 0);
		for (int i = 0; i < n; ++i)
		{
			updateBIT(i + 1, arr[i]);
		}

	}
	void updateBIT(int j, int diff)
	{
		while (j <= n)
		{
			bit[j] += diff;
			j += j & -j;
		}
	}
	int sumRange(int i, int j)
	{
		return getSum(j + 1) - getSum(i);
	}
	int getSum(int j)
	{
		int sum = 0;
		while (j > 0)
		{
			sum += bit[j];
			j -= j & -j;

		}
		return sum;
	}
	void update(int i, int val) {
		int diff = val - arr[i];
		arr[i] = val;
		updateBIT(i + 1, diff);
	}


};

//class NumArray {
//	int bit[];
//	int arr[];
//	int n;
//
//	 NumArray(int[] nums) {
//		n = nums.length;
//		arr = Arrays.copyOf(nums, n);
//		bit = new int[n + 1];
//		for (int i = 0; i < n; i++) updateBIT(i + 1, arr[i]);
//	}
//
//	void update(int i, int val) {
//		int diff = val - arr[i];
//		arr[i] = val;
//		updateBIT(i + 1, diff);
//	}
//
//	void updateBIT(int j, int diff) {
//		while (j <= n) {
//			bit[j] += diff;
//			j += j & -j;
//		}
//	}
//
//	public int sumRange(int i, int j) {
//		return getSum(j + 1) - getSum(i);
//	}
//
//	int getSum(int j) {
//		int sum = 0;
//		while (j > 0) {
//			sum += bit[j];
//			j -= j & -j;
//		}
//		return sum;
//	}
//}
//class NumArray {
//public:
//	struct SegmentTreeNode {
//		int lo, hi, sum;
//		SegmentTreeNode *left, *right;
//		SegmentTreeNode(int lo, int hi) {
//			this->lo = lo;
//			this->hi = hi;
//			this->sum = 0;
//			this->left = NULL;
//			this->right = NULL;
//		}
//	};
//	SegmentTreeNode *root;
//	vector<int>nums;
//	NumArray(vector<int> &nums) {
//		this->nums = nums;
//		root = build(0, nums.size() - 1);
//	}
//	SegmentTreeNode* build(int lo, int hi) {
//		if (hi < lo)
//			return NULL;
//		int mi = (lo + hi) / 2;
//		SegmentTreeNode *root = new SegmentTreeNode(lo, hi);
//		if (lo == hi) {
//			root->sum = nums[lo];
//			return root;
//		}
//		root->left = build(lo, mi);
//		root->right = build(mi + 1, hi);
//		root->sum = root->left->sum + root->right->sum;
//		return root;
//	}
//	void update(int i, int val) {
//		update(root, i, val);
//	}
//	void update(SegmentTreeNode *root, int i, int val) {
//		if (root->lo == root->hi) {
//			root->sum = val;
//			return;
//		}
//		int mi = (root->lo + root->hi) / 2;
//		if (i <= mi)
//			update(root->left, i, val);
//		else
//			update(root->right, i, val);
//		root->sum = root->left->sum + root->right->sum;
//	}
//
//	int sumRange(int i, int j) {
//		return sumRange(root, i, j);
//	}
//
//	int sumRange(SegmentTreeNode *root, int i, int j) {
//		int mi = (root->lo + root->hi) / 2;
//		if (i == root->lo && j == root->hi)
//			return root->sum;
//		else if (j <= mi)
//			return sumRange(root->left, i, j);
//		else if (mi < i)
//			return sumRange(root->right, i, j);
//		else
//			return sumRange(root->left, i, mi) + sumRange(root->right, mi + 1, j);
//	}
//};
//class NumArray {
//public:
//	NumArray(vector<int> &nums) {
//		m_nums.assign(nums.begin(), nums.end());
//		int sum = 0;
//		for (int i = 0; i < nums.size(); ++i)
//		{
//			sum += nums[i];
//			m_res.push_back(sum);
//		}
//	}
//
//	void update(int i, int val) {
//
//		int b = m_nums[i];
//		transform(m_res.begin() + i, m_res.end(), m_res.begin() + i, [val, b ](int a){ return a + (val - b);  });
//		m_nums[i] = val;
//	}
//
//	int sumRange(int i, int j) {
//		if (i == 0)
//		{
//			return m_res[j];
//		}
//		else
//		{
//			return m_res[j] - m_res[i - 1];
//		}
//	}
//	vector<int> m_nums;
//	vector<int> m_res;
//};
int main()
{
	return 0;
}