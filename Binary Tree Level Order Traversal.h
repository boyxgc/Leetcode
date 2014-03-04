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
        vector<TreeNode *> *queue = new vector<TreeNode *>();
        if(root) {
            queue->push_back(root);
            while(queue && queue->size() > 0) {
                vector<TreeNode *> *tmp = new vector<TreeNode *>();
                vector<int> tmpres;
                for(int i = 0; i < queue->size(); ++i) {
                    tmpres.push_back((*queue)[i]->val);
                    if((*queue)[i]->left) tmp->push_back((*queue)[i]->left);
                    if((*queue)[i]->right) tmp->push_back((*queue)[i]->right);
                }
                
                res.push_back(tmpres);
                queue = tmp;
            }
        }
        
        return res;
    }
};