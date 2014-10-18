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
    int minDepth(TreeNode *root) {
        if(!root) return 0;
        
        if(!root->left && !root->right) return 1;
        
        int minh = INT_MAX;
        if(root->left) {
            minh = min(minh, minDepth(root->left));
        }
        if(root->right) {
            minh = min(minh, minDepth(root->right));
        }
        
        return minh + 1;
    }
};