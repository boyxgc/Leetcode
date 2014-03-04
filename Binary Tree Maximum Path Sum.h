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
    int maxPathSum(TreeNode *root) {
        if(!root)
            return 0;
        int sum = INT_MIN;
        maxPath(root, sum);
        
        return sum;
    }
    
    int maxPath (TreeNode *root, int & maxsofar) {
        if(root == NULL)
            return 0 ;
        int l = maxPath(root->left, maxsofar);
        int r = maxPath(root->right, maxsofar);
        int m = root->val;
        if(l > 0)
            m += l;
        if(r > 0)
            m += r;
        maxsofar = max(maxsofar, m);
        if(max(l,r) > 0)
            return max(l, r)+root->val;
        else 
            return root->val;
    }
};