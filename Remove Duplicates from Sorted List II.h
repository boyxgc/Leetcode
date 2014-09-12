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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *newhead = new ListNode(0);
        newhead->next = head;
        
        ListNode *p = newhead;
        while(p && p->next && p->next->next) {
            if(p->next->val == p->next->next->val) {
                int val = p->next->val;
                while(p->next && p->next->val == val) {
                    ListNode *tmp = p->next;
                    p->next = p->next->next;
                    
                    delete tmp;
                }
            } else {
                p = p->next;
            }
        }
        
        return newhead->next;
    }
};