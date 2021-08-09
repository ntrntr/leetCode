/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		vector<ListNode*> a;
		vector<ListNode*> b;
		while (headA)
		{
			a.push_back(headA);
			headA = headA->next;
		}
		while (headB)
		{
			b.push_back(headB);
			headB = headB->next;
		}
		ListNode* ret = nullptr;
		int i = a.size() - 1;
		int j = b.size() - 1;
		while (i >= 0 && j >= 0)
		{
			if (a[i] == b[j])
			{
				ret = a[i];
				i--;
				j--;

			}
			else
			{
				break;
			}
		}
		return ret;
	}
};