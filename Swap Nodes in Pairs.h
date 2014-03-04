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
    ListNode *swapPairs(ListNode *head) {
        if(!head || !head->next) return head;
        ListNode *newhead = new ListNode(0);
        ListNode *p = newhead;
        ListNode *q = head;
        newhead->next = head;
        while(q && q->next){
            ListNode *tmp = q->next->next;
            q->next->next = p->next;
            p->next = q->next;
            q->next = tmp;
            p = q;
            q = q->next;
        }
        return newhead->next;
    }
};