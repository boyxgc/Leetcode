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
    int sumNumbers(TreeNode *root) {
        int res = 0;
        sum(root, 0, res);
        return res;
    }
    
    void sum(TreeNode * root, int parent, int & res) {
        if(!root) {
            return;
        }
        if(!root->left && !root->right) {
            res += parent*10 + root->val;
            return;
        }
        if(root->left) {
            sum(root->left, parent*10 + root->val, res);
        }
        if(root->right) {
            sum(root->right, parent*10 + root->val, res);
        }
    }
};