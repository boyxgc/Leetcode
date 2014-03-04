/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public int minDepth(TreeNode root) {
        if(root == null) 
            return 0;
        return depth(root);
    }
    
    public int depth(TreeNode root) {
        if(root == null)
            return 100000;
        if(root.left == null && root.right == null)
            return 1;
        return Math.min(depth(root.left), depth(root.right)) + 1;
    }
}