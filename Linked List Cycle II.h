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
    ListNode *detectCycle(ListNode *head) {
        /*
        unordered_set<ListNode *> hash;
        
        ListNode*pos = head;
        while(pos) {
            if(hash.find(pos) == hash.end()) {
                hash.insert(pos);
            } else {
                return pos;
            }
            pos = pos->next;
        }
        return NULL;
        */
        // no extra mm
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {// find cycle first
                fast = head;
                while(slow != fast) {// find start of the cycle
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};