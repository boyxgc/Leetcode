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
        vector<int> path;
        vector<vector<int> > res;
        generatePaths(root, path, sum, res);
        
        return res;
    }
    
private:
    void generatePaths(TreeNode * r, vector<int> &path, int sum, vector<vector<int> > &res) {
        if(!r) return;
        if(!r->left && !r->right) {
            if(r->val == sum) {
                vector<int> cpy(path);
                cpy.push_back(sum);
                res.push_back(cpy);
            }
            return;
        }
        path.push_back(r->val);
        if(r->left) generatePaths(r->left, path, sum - r->val, res);
        if(r->right) generatePaths(r->right, path, sum - r->val, res);
        path.pop_back();
    }
};