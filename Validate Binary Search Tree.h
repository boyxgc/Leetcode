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
        
        return validate(root, INT_MIN, INT_MAX);
    }
    
    bool validate(TreeNode *root, int min, int max) {
        if(!root) return true;
        
        if(root->val <= min || root->val >= max) return false;
        
        return validate(root->left, min, root->val) && validate(root->right, root->val, max);
    }
};
 
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