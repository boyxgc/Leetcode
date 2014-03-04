/**
 * Definition for binary tree with next pointer.
 * public class TreeLinkNode {
 *     int val;
 *     TreeLinkNode left, right, next;
 *     TreeLinkNode(int x) { val = x; }
 * }
 */
public class Solution {
    public void connect(TreeLinkNode root) {
        if(root == null)
            return;
            
        TreeLinkNode up = root;
        up.next = null;
        TreeLinkNode down = null;
        
        while(up != null && (up.left != null || up.right != null)) {
            if(up.left != null){
                down = up.left;
            } else {
                down = up.right;
            }
            TreeLinkNode pos1 = up;
            TreeLinkNode pos2 = down;
            while(pos1 != null) {
                if(pos1.left != null && pos1.left != pos2) {
                    pos2.next = pos1.left;
                    pos2 = pos2.next;
                }
                if(pos1.right != null && pos1.right != pos2) {
                    pos2.next = pos1.right;
                    pos2 = pos2.next;
                }
                pos1 = pos1.next;
            }
            pos2.next = null;
            while(down != null && (down.left == null && down.right == null)) {
                down = down.next;
            }
            up = down;
        }
    }
}