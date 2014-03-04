/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if(!head) return NULL;
        if(!head->next) return new TreeNode(head->val);
        ListNode *p = head;
        ListNode *q = head;
        ListNode *p_prev = NULL;
        while(q->next && q->next->next){
            p_prev = p;
            p = p->next;
            q = q->next->next;
        }
        TreeNode *root = new TreeNode(p->val);
        
        if(p_prev) {
            p_prev->next = NULL;
            root->left = sortedListToBST(head);
        }
        root->right = sortedListToBST(p->next);
    
        return root;
    }
};