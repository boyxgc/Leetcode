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
    TreeNode *build(vector<int> &inorder, int inlow, int inhigh, vector<int> &postorder, int post) {
        if(postorder.size() == 0 || inorder.size() == 0)
            return NULL;
        if(inlow > inhigh || post < 0)
            return NULL;
        int rootval = postorder[post];
        TreeNode *root = new TreeNode(rootval);
        
        int i = inlow;
        for(; i <= inhigh; ++i)
            if(inorder[i] == rootval) break;
        
        root->left = build(inorder, inlow, i-1, postorder, post-1-inhigh+i);
        root->right = build(inorder, i+1, inhigh, postorder, post-1);
        
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return build(inorder,0, inorder.size()-1, postorder, postorder.size()-1);
    }
};