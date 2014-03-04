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
    /*
    ListNode * reverseList(ListNode * l){
        ListNode *prev = NULL;
        ListNode *p = l;
        while(p){
            ListNode *tmp = p->next;
            p->next = prev;
            prev = p;
            p = tmp;
        }
        return prev;
    }*/
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *l1_rev = l1;//reverseList(l1);
        ListNode *l2_rev = l2;//reverseList(l2);
        ListNode *ret = new ListNode(0);
        ListNode *pos = ret;
        int carry = 0;
        while(l1_rev && l2_rev){
            int sum = carry+ l1_rev->val + l2_rev->val;
            ListNode *node = new ListNode(sum%10);
            carry = sum/10;
            pos->next = node;
            pos = node;
            l1_rev = l1_rev->next;
            l2_rev = l2_rev->next;
        }
        while(l1_rev){
            int sum = carry+ l1_rev->val;
            ListNode *node = new ListNode(sum%10);
            carry = sum/10;
            pos->next = node;
            pos = node;
            l1_rev = l1_rev->next;
        }
        while(l2_rev) {
            int sum = carry+ l2_rev->val;
            ListNode *node = new ListNode(sum%10);
            carry = sum/10;
            pos->next = node;
            pos = node;
            l2_rev = l2_rev->next;
        }
        if(carry){
            ListNode *node = new ListNode(1);
            pos->next = node;
        }
        
        return ret->next;//reverseList(ret->next);
    }
};