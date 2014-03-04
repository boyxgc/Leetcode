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
        stack<TreeNode *> st;
        
        TreeNode *current;
        while(current || !st.empty()) {
            if(current){
                st.push(current);
                current = current->left;
            } else {
                TreeNode *top = st.top();
                st.pop();
                ret.push_back(top->val);
                st.push(top->right);
            }
        }
        return ret;
    }
};