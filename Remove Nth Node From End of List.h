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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        
        ListNode *newhead = new ListNode(0);
        newhead->next = head;
        
        ListNode *pos1 = newhead;
        ListNode *pos2 = newhead;
        
        int count = 0;
        while(pos2) {
            if(count <= n){
                pos2 = pos2->next;
                count++;
            } else {
                pos2 = pos2->next;
                pos1 = pos1->next;
            }
        }
        
        ListNode *tmp = pos1->next;
        pos1->next = tmp->next;
        delete tmp;
        
        return newhead->next;
    }
};