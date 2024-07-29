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
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* cur = head->next, *pre = head, *nex = cur->next, *cur2 = cur->next;
        head->next = nullptr;
        int max_v = INT_MIN;
        while(cur != nullptr)
        {
            if(cur2 != nullptr)
                cur->next = pre, pre = cur, cur = nex, nex = nex->next, cur2 = cur2->next->next;
            else
            {
                max_v = max(max_v, cur->val + pre->val);
                cur = cur->next, pre = pre->next;
            }
        }
        return max_v;
    }
};