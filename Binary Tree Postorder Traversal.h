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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ret;
        if(!root) return ret;
        
        stack<TreeNode *> st;
        st.push(root);
        
        TreeNode *curr = NULL;// current node on top of stack
        TreeNode *prev = NULL;// last traversed node
        while(!st.empty()){
            curr = st.top();
        
            if(!prev || curr == prev->left || curr == prev->right){// going down
                if(curr->left){
                    st.push(curr->left);
                } else if(curr->right){
                    st.push(curr->right);
                } else {
                    ret.push_back(curr->val);
                    st.pop();
                }
            } else if(prev == curr->left){// going up from left
                if(curr->right){
                    st.push(curr->right);
                } else {
                    ret.push_back(curr->val);
                    st.pop();
                }
            } else{ //if(prev == curr->right){// going up from right
                ret.push_back(curr->val);
                st.pop();
            }
            
            prev = curr; // record last traversed node
        }
        return ret;
    }
};