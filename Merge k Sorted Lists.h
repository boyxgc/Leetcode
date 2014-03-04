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
    struct compare {
      bool operator() (const ListNode *n1, const ListNode*n2){return n1->val > n2->val;}
    };
    
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.size() == 0)
            return NULL;
        priority_queue<ListNode *, vector<ListNode*>, compare> pq;
        for(int i = 0; i < lists.size(); ++i){
            if(lists[i])
                pq.push(lists[i]);
        }
        ListNode *head = new ListNode(0);
        ListNode *pos = head;
        while(!pq.empty()) {
            ListNode *top = pq.top();
            pq.pop();
            pos->next = top;
            if(top->next){
                pq.push(top->next);
            }
            pos = pos->next;
        }
        return head->next;
    }
};