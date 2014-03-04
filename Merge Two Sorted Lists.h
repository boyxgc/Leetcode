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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode(0);
       
        ListNode *pos = head;
        while(l1 && l2) {
            if(l1->val < l2->val) {
                pos->next = l1;
                l1 = l1->next;
            }  else {
                pos->next = l2;
                l2 = l2->next;
            }
            pos = pos->next;
        }
        while(l1) {
            pos->next = l1;
            l1 = l1->next;
            pos = pos->next;
        }
        while(l2) {
            pos->next = l2;
            l2 = l2->next;
            pos = pos->next;
        }
        
        return head->next;
    }
};