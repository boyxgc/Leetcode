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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ret;
        if(!root) return ret;
        
        stack<TreeNode *> st;
        TreeNode * curr = root;
        
        while(curr || !st.empty()) {
            if(curr) {
                st.push(curr);
                curr = curr->left;
            } else {
                TreeNode * top = st.top();
                st.pop();
                ret.push_back(top->val);
                
                if(top->right) {
                    curr = top->right;
                }
            }
        }
        
        return ret;
    }
};