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
    ListNode *partition(ListNode *head, int x) {
        if(!head || !head->next) return head;
        
        ListNode *head1 = new ListNode(0);
        ListNode *head2 = new ListNode(0);
        
        ListNode *p1 = head1;
        ListNode *p2 = head2;
        
        ListNode *p = head;
        while(p) {
            ListNode *next = p->next;
            p->next = NULL;
            if(p->val < x) {
                p1->next = p;
                p1 = p;
            } else {
                p2->next = p;
                p2 = p;
            }
            p = next;
        }
        p1->next = head2->next;
        
        return head1->next;
    }
};