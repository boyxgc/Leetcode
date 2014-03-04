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
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *pos1 = head;
        ListNode *pos2 = NULL;
        
        while(pos1) {
            pos2 = pos1->next;
            while(pos2 && pos2->val == pos1->val) {
                ListNode * tmp = pos2;
                pos2 = pos2->next;
                delete tmp;
            }
            pos1->next = pos2;
            pos1 = pos1->next;
        }
        return head;
    }
};