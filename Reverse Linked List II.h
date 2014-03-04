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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(!head) return NULL;
        ListNode *newhead = new ListNode(0);
        newhead->next = head;
        int cn = 0;
        ListNode *pos = newhead;
        while(++cn < m && pos){
            pos = pos->next;
        }
        ListNode *pos2 = pos->next;
        while(cn++ < n && pos2->next){
            ListNode *tmp = pos2->next->next;
            pos2->next->next = pos->next;
            pos->next = pos2->next;
            pos2->next = tmp;
        }
        return newhead->next;
    }
};