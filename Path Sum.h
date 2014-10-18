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
    bool hasPathSum(TreeNode *root, int sum) {
        if(!root) return false;
        
        if(!root->left && !root->right) {
            return sum == root->val;
        }
        
        int remainsum = sum - root->val;
        return hasPathSum(root->left, remainsum) || hasPathSum(root->right, remainsum);
    }
};