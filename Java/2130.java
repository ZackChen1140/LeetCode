/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public int pairSum(ListNode head) {
        ListNode pre = head, cur = head.next, nex = cur.next, cur2 = cur.next;
        int max_v = Integer.MIN_VALUE;
        head.next = null;
        while(cur != null)
        {
            if(cur2 != null)
            {
                cur.next = pre;
                pre = cur; cur = nex; nex = cur.next;
                cur2 = cur2.next.next;
            }
            else
            {
                max_v = Math.max(max_v, cur.val + pre.val);
                cur = cur.next;
                pre = pre.next;
            }
        }
        return max_v;
    }
}