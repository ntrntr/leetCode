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
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode dummy(-1);
		dummy.next = head;
		ListNode *prev_m, *prev = &dummy;
		for (int i = 1; i <= n; ++i) {
			if (i == m) prev_m = prev;
			if (i > m && i <= n) { // prev_m ºÍ prev ¾²Ö¹²»¶¯
				prev->next = head->next;
				head->next = prev_m->next;
				prev_m->next = head;
		head = prev;
	}
	prev = head;
	head = head->next;
	}
	return dummy.next;

		/*if (m > n)
		{
			return reverseBetween(head, n, m);
		}
		if (m == n)
		{
			return head;
		}
		ListNode* myHead = new ListNode(-1);
		myHead->next = head;
		ListNode* p = head;
		ListNode* prev = myHead;
		ListNode* pivot = head;
		ListNode* begin;
		for (int i = 1; i <= n; ++i)
		{
			if (i < m)
			{
				prev = p;
				p = p->next;
			}
			else if (i == m)
			{
				begin = p;
				pivot = p;
				p = p->next;
			}
			else if (i >m && i < n)
			{
				ListNode* tmp = p->next;
				p->next = pivot;
				pivot = p;
				p = tmp;
			}
			else if (i == n)
			{
				ListNode* tmp = p->next;
				prev->next = p;
				p->next = pivot;
				begin->next = tmp;
			}
		}
		
		return myHead->next;*/

	}
};
int main()
{
	Solution s;
	ListNode a(1);
	a.next = new ListNode(2);
	a.next->next = new ListNode(3);
	s.reverseBetween(&a, 1, 3);
	return 0;
}