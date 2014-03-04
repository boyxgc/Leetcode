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
    int balance(TreeNode *root){
        if(!root) return 0;
        int left = balance(root->left);
        if(left == -1) return -1;
        int right = balance(root->right);
        if(right == -1) return -1;
        return (abs(left-right) > 1) ? -1 : max(left, right)+1;
    }
    bool isBalanced(TreeNode *root) {
        return !(balance(root) == -1);
    }
};