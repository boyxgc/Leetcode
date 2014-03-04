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
        if(!head)
            return head;
        ListNode *newhead = new ListNode(0);
        ListNode *p1 = newhead;
        ListNode *p2 = head;
        
        while(p2) {
            if(p2->next && p2->next->val == p2->val){
                int val = p2->val;
                while(p2 && p2->val == val){
                    p2 = p2->next;
                }
            } else {
                p1->next = p2;
                p1 = p1->next;
                p2 = p2->next;
                p1->next = NULL;//cut connection from original list
            }
        }
        return newhead->next;
    }
};