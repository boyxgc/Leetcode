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
    void reorderList(ListNode *head) {
        if(!head || !head->next)
            return;
        ListNode *p = head;
        ListNode *q = head;
        
        while(q->next && q->next->next) {
            p = p->next;
            q = q->next->next;
        }
        
        //p now is the mid pt
        //reverse p->next to end 
        q = p->next;
        ListNode *tmp = NULL;
        while(q->next) {
            //tmp = p->next;
            //p->next = q->next;
            //q->next = q->next->next;
            //p->next->next = tmp;
            //second way
            tmp = q->next->next;
            q->next->next = p->next;
            p->next = q->next;
            q->next = tmp;
        }
        
        //insert
        q = head;
        while(p->next && q != p) {
            tmp = p->next;
            p->next = tmp->next;
            tmp->next = q->next;
            q->next = tmp;
            q = tmp->next;
        }
        
        //return head;
    }
};