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
    
    void inorderTraverse(TreeNode *root, TreeNode * &prev, TreeNode *&first, TreeNode *&second){
        if(!root)
            return;
        inorderTraverse(root->left, prev, first, second);
        if(prev) {
            if(prev->val > root->val){
                if(first == NULL)
                    first = prev;
                //else // canot put else here, case: 1, 3, 2, 4 
                second = root;
            }
        }
        prev = root;
        inorderTraverse(root->right, prev, first, second);
    }
    void recoverTree(TreeNode *root) {
        TreeNode *prev = NULL;
        TreeNode *first = NULL;
        TreeNode *second = NULL;
        inorderTraverse(root, prev, first, second);
        int tmp = first->val;
        first->val = second->val;
        second->val = tmp;
    }
};