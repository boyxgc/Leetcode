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
    vector<TreeNode *> gene(int low, int high){
        vector<TreeNode *>ret;
        if(high < low){
            ret.push_back(NULL);
            return ret;
        }
        for(int i = low; i <= high; ++i){
            vector<TreeNode *> lefts = gene(low,i-1);
            vector<TreeNode *> rights = gene(i+1, high);
            
            for(int j = 0; j < lefts.size(); ++j) {
                for(int k = 0; k < rights.size(); ++k) {
                    TreeNode *root = new TreeNode(i);
                    root->left = lefts[j];
                    root->right = rights[k];
                    ret.push_back(root);
                }
            }
        }
        
    }
    vector<TreeNode *> generateTrees(int n) {
        return gene(1, n);
    }
};