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
    bool isSymmetric(TreeNode *root) {
        if(!root) return true;
        
        return checkSym(root->left, root->right);
    }
    
private:
    bool checkSym(TreeNode *r1, TreeNode *r2) {
        if(!r1 && !r2) return true;
        if(!r1 || !r2) return false;
        if(r1->val != r2->val) return false;
        
        return checkSym(r1->left, r2->right) && checkSym(r1->right, r2->left);
    }
};