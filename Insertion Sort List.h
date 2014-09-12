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
    ListNode *insertionSortList(ListNode *head) {
        if(!head || !head->next) return head;
        
        ListNode *newhead = new ListNode(0);
        ListNode *p = head;
        while(p) {
            ListNode *sortp = newhead;
            while(sortp && sortp->next && p->val > sortp->next->val) {
                sortp = sortp->next;
            }
            ListNode * next = p->next;
            p->next =sortp->next;
            sortp->next = p;
            
            p = next;
        }
        return newhead->next;
    }
};