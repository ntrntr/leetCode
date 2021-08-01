#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto* helper = head;
        if (k <= 1)
        {
            return head;
        }
        vector<int> values(k, -1);
        ListNode* first_node = nullptr;
        int current_i = -1;
        while(helper != nullptr)
        {
            if (current_i == -1)
            {
                first_node = helper;
            }
            current_i++;
            values[current_i] = helper->val;
            if(current_i == k-1)
            {
                for(auto j=k-1; j >=0; j--)
                {
                    first_node->val = values[j];
                    first_node = first_node->next;
                }
                first_node = nullptr;
                current_i = -1;
            }
            helper = helper->next;
        }
        return head;
    }
};

int main(void)
{
    return 1;
}