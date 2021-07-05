/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		auto helper = ListNode(0);
		auto jinwei = 0;
		auto* cur = &helper;
		while (l1 && l2)
		{
			auto val = (l1->val + l2->val + jinwei) % 10;
			jinwei = (l1->val + l2->val + jinwei) / 10;
			cur->next = new ListNode(val);
			cur = cur->next;
			l1 = l1->next;
			l2 = l2->next;
		}
		ListNode* left = nullptr;
		if (l1)
		{
			left = l1;
		}
		else
		{
			left = l2;
		}
		while (left)
		{
			auto val = (left->val + jinwei) % 10;
			jinwei = (left->val + jinwei) / 10;
			cur->next = new ListNode(val);
			cur = cur->next;
			left = left->next;
		}
		if (jinwei > 0)
		{
			cur->next = new ListNode(jinwei);
		}
		return helper.next;
	}
};

int main(void)
{
	return 0;
}