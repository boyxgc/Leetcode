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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > res;
        
        if(!root) return res;
        
        vector<TreeNode *> level;
        level.push_back(root);
        
        while(!level.empty()) {
            vector<int> intv;
            vector<TreeNode *> nodev;
            
            for(int i = 0; i < level.size(); ++i) {
                TreeNode *node = level[i];
                intv.push_back(node->val);
                
                if(node->left) {
                    nodev.push_back(node->left);
                }
                if(node->right){
                    nodev.push_back(node->right);
                }
            }
            res.push_back(intv);
            level = nodev;
        }
        return res;
    }
};