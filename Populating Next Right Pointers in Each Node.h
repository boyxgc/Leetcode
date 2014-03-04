/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL)
            return;
        TreeLinkNode * top;
        TreeLinkNode * cur;
        
        top = root;
        top->next = NULL;
        cur = top->left;
        
        while(cur != NULL) {
            TreeLinkNode *tmptop = top;
            while(tmptop != NULL && cur != NULL) {
                cur->next = tmptop->right;
                cur->next->next = (tmptop->next == NULL) ? NULL : tmptop->next->left;
                
                tmptop = tmptop->next;
                cur = cur->next->next;
            }
            top = top->left;
            cur = top->left;
        }
    }
};