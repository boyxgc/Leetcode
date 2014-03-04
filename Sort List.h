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
        
        ListNode *p = head, *q = head;
        while(q->next && q->next->next){
            p = p->next;
            q = q->next->next;
        }
        // p is the mid of list,
        ListNode *tmp = p->next;
        p->next = NULL;// cut into halvies
        ListNode *firsthalf = sortList(head);
        ListNode *secondhalf = sortList(tmp);
        
        ListNode *newhead = new ListNode(0);
        ListNode *pos = newhead;
        
        while(firsthalf && secondhalf){
            if(firsthalf->val < secondhalf->val){
                pos->next = firsthalf;
                firsthalf = firsthalf->next;
            } else {
                pos->next = secondhalf;
                secondhalf = secondhalf->next;
            }
            pos = pos->next;
        }
        while(firsthalf){
            pos->next = firsthalf;
            firsthalf = firsthalf->next;
            pos = pos->next;
        }
        while(secondhalf){
            pos->next = secondhalf;
            secondhalf = secondhalf->next;
            pos = pos->next;
        }
        return newhead->next;
    }
};