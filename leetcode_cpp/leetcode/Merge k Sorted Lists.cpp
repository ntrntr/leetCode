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
typedef pair<ListNode*, int> PAIR;
bool comp(const PAIR& a, const PAIR& b)
{

	return x.second < y.second;
}
class Solution {
public:
	/*ListNode* mergeKLists(vector<ListNode*>& lists) {
	if(lists.size() == 0)
	{
	return NULL;
	}
	ListNode* head = NULL;
	ListNode* p = NULL;
	vector<bool> isFinished(lists.size(), false); 
	int tmp = INT_MAX;
	int id = 0;
	int count = 0;
	int judgecount = 0;
	for(int i = 0; i < lists.size(); ++i)
	{
	if(lists[i] == NULL)
	{
	isFinished[i] = true;
	++judgecount; 
	}
	++count;
	for(int j = 0; j < lists.size(); ++j)
	{
	if(!isFinished[i] && tmp > lists[i]->val)
	{
	tmp = lists[i]->val;
	id = i;
	}
	}

	if(count == 1)
	{
	p = new ListNode(tmp);
	head = p;
	lists[i] = lists[i]->next; 
	p = p->next;
	}
	else
	{
	p = new ListNode(tmp);
	lists[i] = lists[i]->next; 
	p = p->next;
	}


	}

	return head;
	}*/
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.size() == 0)
		{
			return nullptr;
		}
		ListNode* p = lists[0];
		for (int i = 1; i < lists.size(); ++i)
		{
			p = mergeTwoSortedList(p, lists[i]);
		}
		return p;
	}
	void mergeTwoSortedList(ListNode* l1, ListNode *l2)
	{

		ListNode head(-1);
		ListNode* p = &head;
		for (;l1 != nullptr || l2 != nullptr; p = p->next)
		{
			int val1 = l1 == nullptr ? INT_MAX: l1->val;
			int val2 = l2 == nullptr ? INT_MAX: l2->val;
			if (val1 < val2)
			{
				p->next = l1;
				l1 = l1->next;
			}
			else
			{
				p->next = l2;
				l2 = l2->next;
			}
		}
		return head.next;
	}
};
int main()
{
	Solution s;
	ListNode a(1);
	a.next = new ListNode(2);
	a.next->next = new ListNode(2);

	ListNode b(1);
	b.next = new ListNode(1);
	b.next->next = new ListNode(2);
	vector<ListNode*> tt;
	tt.push_back(&a);
	tt.push_back(&b);
	ListNode* tmp = s.mergeKLists(tt);
	return 0;
}