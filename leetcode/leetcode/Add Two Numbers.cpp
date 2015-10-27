#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;
struct ListNode {
	    int val;
	    ListNode *next;
		//ListNode(){}
	    ListNode(int x) : val(x), next(NULL) {}
	 };
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* head = new ListNode(0);
		ListNode* r = head;
		int carry = 0;
		for (ListNode* p = l1,* q = l2; p != nullptr || q != nullptr; p = p == nullptr ? nullptr:p->next, 
			q = q == nullptr ? nullptr:q->next)
		{
			const int a = p == nullptr ? 0:p->val;
			const int b = q == nullptr ? 0:q->val;
			r->next = new ListNode((a + b + carry) % 10);
			carry = (a + b + carry) / 10;
			r = r->next;
		}
		if (carry > 0)
		{
			r->next = new ListNode(carry);
			carry = 0;
		}
		return head->next;
		/*ListNode* p = l1;
		ListNode* q = l2;
		ListNode* pre = r;
		int jinwei = 0;
		while (p != NULL && q != NULL)
		{
			if (p != NULL && q != NULL)
			{
				
				int tmp = p->val + q->val + jinwei;
				jinwei = tmp / 10;
				tmp = tmp % 10;
				if (r == NULL)
				{
					
					r = new ListNode(tmp);
					pre->next = r;
					pre = r;
				}
				else
				{
				r->val = tmp;
				}
				r = r->next;
				p = p->next;
				q = q->next;
			}
		}
		if (p != NULL)
		{
			r = p;
			pre->next = r;
			pre = r;
			while (jinwei && r)
			{
				r->val += jinwei;
				jinwei = r->val / 10;
				r->val %= 10;
				pre = r;
				r = r->next;
				
			}
			if (jinwei > 0)
			{
				r = new ListNode(jinwei);
				pre->next = r;
				pre = r;
			}
			return head;
		}
		if (q != NULL)
		{
			r = q;
			pre->next = r;
			pre = r;
			while (jinwei && r)
			{
				r->val += jinwei;
				jinwei = r->val / 10;
				r->val %= 10;
				pre = r;
				r = r->next;
			}
			if (jinwei > 0)
			{
				r = new ListNode(jinwei);
				pre->next = r;
				pre = r;
			}
			return head;
		}
		if (jinwei > 0)
		{
			r = new ListNode(jinwei);
			pre->next = r;
			pre = r;
		}*/
		//return head;
	}
};
int main()
{
	Solution s;
	ListNode a(8);
	ListNode a1(9);
	ListNode a2(9);
	a.next = &a1;
	a1.next = &a2;
	ListNode b(2);
	s.addTwoNumbers(&a, &b);
	return 0;
}