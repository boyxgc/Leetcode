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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > ret;
        if(!root)
            return ret;
        stack<TreeNode *> st;
        
        int level = 1;
        st.push(root);
        while(!st.empty()) {
            stack<TreeNode *> tmpst;
            vector<int> tmpv;
            while(!st.empty()) {
                TreeNode *node = st.top();
                st.pop();
                tmpv.push_back(node->val);
                if(level%2){//left first
                    if(node->left)
                        tmpst.push(node->left);
                    if(node->right)
                        tmpst.push(node->right);
                }else {//right first
                    if(node->right)
                        tmpst.push(node->right);
                    if(node->left)
                        tmpst.push(node->left);
                }
            }
            ret.push_back(tmpv);
            st = tmpst;
            level++;
        }
        return ret;
    }
};