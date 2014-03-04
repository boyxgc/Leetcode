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
    ListNode *rotateRight(ListNode *head, int k) {
        if(!head || k == 0 || !head->next) 
            return head;
        int len = 0;
        ListNode *pos = head;
        while(pos) {
            len++;
            pos = pos->next;
        }
        
        k = k%len;
        if(k == 0)
            return head;
        
        ListNode *pos1 = head;
        ListNode *pos2 = head;
        
        int count = k;
        for(int i = 0; i < count; ++i)
            pos2 = pos2->next;
        
        while(pos2->next) {
            pos2 = pos2->next;
            pos1 = pos1->next;
        }
        
        ListNode *newhead = pos1->next;
        pos1->next = NULL;
        
        pos = head;
        while(pos) {
            pos2->next = pos;
            pos = pos->next;
            pos2 = pos2->next;
        }
        
        return newhead;
    }
};