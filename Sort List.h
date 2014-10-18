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
    ListNode *sortList(ListNode *head) {
        if(!head || !head->next) return head;
        
        ListNode *p1 = head;
        ListNode *p2 = head;
        
        while(p2 && p2->next && p2->next->next) {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        
        p2 = p1->next;
        p1->next = NULL;
        
        p1 = sortList(head);
        p2 = sortList(p2);
        
        ListNode *newhead = new ListNode(0);
        ListNode *p = newhead;
        
        while(p1 && p2) {
            if(p1->val < p2->val) {
                p->next = p1;
                p1 = p1->next;
            } else {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }
        if(p1) {
            p->next = p1;
        } else {
            p->next = p2;
        }
        
        return newhead->next;
    }
};