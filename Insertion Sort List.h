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
    ListNode *insertionSortList(ListNode *head) {
        if(!head || !head->next)
            return head;
        ListNode *newhead = new ListNode(0);
        newhead->next = head;
        ListNode *pos = head->next;
        head->next = NULL;
        while(pos){
            ListNode *posnext = pos->next;
            ListNode *tmp = newhead;
            while(tmp->next && tmp->next->val < pos->val){
                tmp = tmp->next;
            }
            pos->next = tmp->next;
            tmp->next = pos;
            pos = posnext;
        }
        return newhead->next;
    }
};