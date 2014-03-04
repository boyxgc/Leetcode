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
    bool inorder(TreeNode *root){
        if(!root)
            return true;
        bool left = inorder(root->left);
        if(!left)
            return false;
        if(prev == NULL){
            prev = root;
        } else {
            if(root->val <= prev->val)
                return false;
            prev = root;
        }
        return inorder(root->right);
    }
    
    bool isValidBST(TreeNode *root) {
        prev = NULL;
        return inorder(root);
    }
};