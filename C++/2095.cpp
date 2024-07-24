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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* cur = head, *hcur = new ListNode(NULL, head), *prehead = hcur;
        while(cur != nullptr && cur->next != nullptr)
        {
            cur = cur->next->next;
            hcur = hcur->next;
        }
        if(hcur->next != head) cur = hcur->next, hcur->next = hcur->next->next, delete cur;
        else head = NULL;
        delete prehead;
        return head;
    }
};