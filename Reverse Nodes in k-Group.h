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
        if(!head || !head->next)
            return head;
        ListNode *newhead = new ListNode(0);
        newhead->next = head;
        ListNode *p = newhead;
        ListNode *q = p->next;
        
        while(q && q->next){
            ListNode *pos = q;
            for(int i = 1; i < k &&pos; ++i)
                pos = pos->next;
            if(!pos) break;//
            
            int count = k;
            while(--count && q->next){// reverse q->next to link to p->next;
                ListNode *tmp = q->next->next;
                q->next->next = p->next;
                p->next = q->next;
                q->next = tmp;
            }
            p = q;
            q = q->next;
        }
        
        return newhead->next;
    }
};