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
		auto helper = l1;
		auto jinwei = 0;
		auto cur = l1;
		ListNode* before = nullptr;
		while (l1 && l2)
		{
			auto val = (l1->val + l2->val + jinwei) % 10;
			jinwei = (l1->val + l2->val + jinwei) / 10;
			cur->val = val;
			before = cur;
			cur = cur->next;
			l1 = l1->next;
			l2 = l2->next;
		}
		if (l1 != nullptr)
		{
			
		}
		else
		{
			before->next = l2;
			cur = l2;
		}
		if (jinwei && cur == nullptr)
		{
			before->next = new ListNode(0);
			cur = before->next;
		}
		while (cur)
		{
			auto val = (cur->val + jinwei) % 10;
			jinwei = (cur->val + jinwei) / 10;
			cur->val = val;
			if(jinwei)
			{
				if(cur->next != nullptr)
				{
					cur = cur->next;
				}
				else
				{
					cur->next = new ListNode(0);
					cur = cur->next;
				}
			}
			else
			{
				break;
			}
		}
		return helper;
	}
};

int main(void)
{
	return 0;
}