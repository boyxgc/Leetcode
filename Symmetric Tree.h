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
        if(!root) 
            return true;
        return DFS_preorder(root, root);// && DFS_midorder(root, root);
        
    }
    
    bool DFS_preorder(TreeNode *root1, TreeNode *root2){
        if(!root1 && !root2)
            return true;
        if(!root1 || !root2)
            return false;
        
        if(root1->val != root2->val)
            return false;
        
        return DFS_preorder(root1->left, root2->right) && DFS_preorder(root1->right, root2->left);
    }
    /*
    bool DFS_midorder(TreeNode *root1, TreeNode *root2){
        if(!root1 && !root2)
            return true;
        if(!root1 || !root2)
            return false;
 
        bool flag1 = DFS_midorder(root1->left, root2->right);
        if(root1->val != root2->val)
            return false;
        bool flag2 = DFS_midorder(root1->right, root2->left);
        
        return flag1 && flag2;
    } */
};