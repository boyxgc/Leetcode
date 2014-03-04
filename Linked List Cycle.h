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
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;
    }
    /*
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return false;
            
        ListNode *pos = head;
        unordered_set<ListNode*> *hash = new unordered_set<ListNode*>();
        while(pos != NULL && !findhash(pos, hash)) {
            pos = pos->next;
        }
        if(pos == NULL)
            return false;
        else
            return true;
    }
    
    bool findhash(ListNode *p, unordered_set<ListNode *> *hash) {
        unordered_set<ListNode *>::const_iterator got = hash->find(p);
        if(got == hash->end()) {
            hash->insert(p);
            return false;
        }
        return true;
    }
    */
};