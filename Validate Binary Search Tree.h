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
    bool isValidBST(TreeNode *root) {
        TreeNode *prev = NULL;
        
        return validate(root, prev);
    }
    
    bool validate(TreeNode *root, TreeNode *&prev) {
        if(!root) return true;
        
        if(!validate(root->left, prev)) return false;
        
        if(prev) {
            if((prev)->val >= root->val) return false;
        }
        prev = root;
        
        return validate(root->right, prev);
    }
    
};