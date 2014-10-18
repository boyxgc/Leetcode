/*Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
*/



/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

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
    void flatten(TreeNode *root) {
        if(!root) return;
        _flatten(root);
        root->left = NULL;
        return;
    }
    
    void _flatten(TreeNode *root) {
        if(!root) return;
        _flatten(root->left);
        _flatten(root->right);
        
        // use root->left to store the end node of the flatten list
        if(root->left) {
            TreeNode *right = root->right;
            root->right = root->left;
            TreeNode *leftend = root->left->left;// end of left
            root->left->left = NULL; // delete left end record
            root->left = NULL;
            
            leftend->right = right;
            
            if(right) {
                root->left = right->left; // end of right
                right->left = NULL; // delete right end record
            } else {
                root->left = leftend;
            }
        } else {
            if(root->right) {
                root->left = root->right->left;
                root->right->left = NULL;
            } else {
                root->left = root;
            }
        }
    }
};

class Solution {
public:
    void flatten(TreeNode *root) {
        if(!root)
            return;
        
        flatten(root->left);
        TreeNode *tmp = root->right;
        root->right = root->left;
        root->left = NULL;
        
        TreeNode *pos = root;
        while(pos->right){
            pos = pos->right;
        }
        pos->right = tmp;
        flatten(tmp);
    }
};