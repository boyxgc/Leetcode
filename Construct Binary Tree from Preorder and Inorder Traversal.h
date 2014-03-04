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
    TreeNode *build(vector<int> &preorder, int pre, vector<int> &inorder, int inlow, int inhigh){
        if(preorder.size() == 0 || inorder.size() == 0
            || pre >= preorder.size() || inlow > inhigh)
            return NULL;
        int rootval = preorder[pre];
        TreeNode *root = new TreeNode(rootval);
        
        int i = inlow;
        for(; i <= inhigh; ++i) {
            if(inorder[i] == rootval) break;
        }
        
        root->left = build(preorder, pre+1, inorder, inlow, i-1);
        root->right = build(preorder, pre+1+i-inlow, inorder, i+1, inhigh);
        
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return build(preorder, 0, inorder, 0, inorder.size()-1);
    }
};