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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > res;
        vector<int> tmpres;
        path(root, sum, tmpres, res);
        tmpres.clear();
        return res;
    }
    
    void path(TreeNode *root, int sum, vector<int> tmpres, vector<vector<int> > & res) {
        if(!root){
            tmpres.clear();
            return;
        }
        if(!root->left && !root->right && root->val == sum) {
            tmpres.push_back(root->val);
            res.push_back(tmpres);
            tmpres.clear();
            return;
        }
       
        tmpres.push_back(root->val);
        if(root->left)
            path(root->left, sum - root->val, tmpres, res);
        if(root->right)
            path(root->right, sum-root->val, tmpres, res);
    }
};