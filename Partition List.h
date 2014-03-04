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
        if(!head)
            return head;
        ListNode *head_left = NULL;
        ListNode *head_right = NULL;
        ListNode *pos_left = NULL;
        ListNode *pos_right = NULL;
        
        ListNode *pos = head;
        while(pos) {
            if(pos->val < x) {
                if(head_left) {
                    pos_left->next = pos;
                    pos_left = pos;
                } else {
                    head_left = pos;
                    pos_left = pos;
                }
            } else {
                if(head_right) {
                    pos_right->next = pos;
                    pos_right = pos;
                } else {
                    head_right = pos;
                    pos_right = pos;
                }
            }
            pos = pos->next;
        }
        if(head_left) {
            pos_left->next = head_right;
            if(head_right)
                pos_right->next = NULL;
            return head_left; 
        } else {
            pos_right->next = NULL;
            return head_right;
        }
    }
};