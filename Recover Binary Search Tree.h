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
    TreeNode *prev;
    TreeNode *first;
    TreeNode *second;
    
    void inorderTraverse(TreeNode *root){
        if(!root)
            return;
        inorderTraverse(root->left);
        if(NULL == prev) {
            prev = root;
        }else{ 
            if(prev->val > root->val){
                if(first == NULL)
                    first = prev;
                second = root;
            }
            prev = root;
        }
        inorderTraverse(root->right);
    }
    void recoverTree(TreeNode *root) {
        prev = NULL;
        first = NULL;
        second = NULL;
        inorderTraverse(root);
        int tmp = first->val;
        first->val = second->val;
        second->val = tmp;
    }
};