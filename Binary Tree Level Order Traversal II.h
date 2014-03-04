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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> >res;
        if(!root)
            return res;
            
        vector<vector<TreeNode*> >nodev;
        vector<TreeNode*> v;
        
        v.push_back(root);
        nodev.push_back(v);
        
        vector<TreeNode*> *tmpv = &v;
        while(tmpv && tmpv->size() > 0) {
            vector<TreeNode*>::const_iterator it;
            vector<TreeNode*> *tmpv2 = new vector<TreeNode*>();//vector<TreeNode*> tmpv2;//new
            for(it = tmpv->begin(); it != tmpv->end(); ++it) {
                if((*it)->left) tmpv2->push_back((*it)->left);
                if((*it)->right) tmpv2->push_back((*it)->right);
            }
            tmpv = tmpv2;
            if(tmpv2->size() > 0)
                nodev.push_back(*tmpv2);
        }
        
        for(int i = nodev.size()-1; i >= 0; i--) {
            vector<int> tmpv3;
            for(int j = 0; j < nodev[i].size(); ++j) {
                tmpv3.push_back((nodev[i][j])->val);
            }
            res.push_back(tmpv3);
        }
        return res;
    }
};