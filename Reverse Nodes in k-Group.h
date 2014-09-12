/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *newhead = new ListNode(0);
        newhead->next = head;

        ListNode *p = newhead;
        while(p) {
            ListNode *q = p->next;
            ListNode *grp_end = probe(p, k);
            if(!grp_end) break;
            while(p->next != grp_end) {
                ListNode *tmp = p->next;
                p->next = q->next;
                q->next = q->next->next;
                p->next->next = tmp;
            }
            
            p = q;
        }
        
        return newhead->next;
    }
    
    ListNode *probe(ListNode *p, int count) {
        while(p && count--) {
            p = p->next;
        }
        return p;
    }
};