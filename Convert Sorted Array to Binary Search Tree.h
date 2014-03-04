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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if(num.size() == 0)
            return NULL;
        if(num.size() == 1)
            return new TreeNode(num[0]);
        if(num.size() == 2){
            TreeNode * root = new TreeNode(num[1]);
            root->left = new TreeNode(num[0]);
            return root;
        }
        TreeNode *root = new TreeNode(num[num.size()/2]);

        vector<int> num2(num.begin()+num.size()/2+1, num.end());
        num.erase(num.begin()+num.size()/2, num.end());// erase second half, remain the first half
        
        root->left = sortedArrayToBST(num);
        root->right = sortedArrayToBST(num2);
        
        return root;
    }
};