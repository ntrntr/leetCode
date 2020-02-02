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
	ListNode* partition(ListNode* head, int x) {
		ListNode lower(-1);
		ListNode higher(-1);
		ListNode* lastlower = &lower;
		ListNode* lasthigher = &higher;
		ListNode* customer = head;
		while (customer)
		{
			if (customer->val < x)
			{
				lastlower->next = customer;
				customer = customer->next;
				lastlower = lastlower->next;
				lastlower->next = NULL;
			}
			else
			{
				lasthigher->next = customer;
				customer = customer->next;
				lasthigher = lasthigher->next;
				lasthigher->next = NULL;
			}
		}
		lastlower->next = higher.next;

		return lower.next;

	}
};
int main()
{
	Solution s;
	ListNode a(1);
	s.partition(&a, 2);
	return 0;
}