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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ret;
        if(!root) return ret;
        
        stack<TreeNode *> st;
        st.push(root);
        while(!st.empty()) {
            TreeNode *curr = st.top();
            st.pop();
            ret.push_back(curr->val);

            if(curr->right)
                st.push(curr->right);
            if(curr->left)
                st.push(curr->left);
        }
        return ret;
    }
};