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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* cur = head->next, *rhead = new ListNode(head->val, nullptr);
        delete head;
        while(cur != nullptr)
        {
            rhead = new ListNode(cur->val, rhead);
            head = cur, cur = cur->next;
            delete head;
        }
        return rhead;
    }
};