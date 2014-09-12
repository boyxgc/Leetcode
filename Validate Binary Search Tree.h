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
    bool isValidBST(TreeNode *root) {
        prev = NULL;
        
        return validate(root);
    }
    
    bool validate(TreeNode *root) {
        if(!root) return true;
        
        if(!validate(root->left)) return false;
        
        if(prev) {
            if(prev->val >= root->val) return false;
        }
        prev = root;
        
        return validate(root->right);
    }
    
};