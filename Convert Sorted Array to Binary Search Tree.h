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
        
        return convert(num, 0, num.size()-1);
    }
    
private:
    TreeNode *convert(vector<int> &num, int l, int r) {
        if(l > r) {
            return NULL;
        }
        
        int mid = (l+r)/2;
        TreeNode *root = new TreeNode(num[mid]);
        root->left = convert(num, l, mid - 1);
        root->right = convert(num, mid+1, r);
        
        return root;
    }
};