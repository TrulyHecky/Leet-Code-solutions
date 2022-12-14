/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    static int max = -1;
    static int sum = 0;
    public static void func(TreeNode root, int level){
        if(root == null) return;
        if(level > max){
            max = level;
            sum = root.val;
        } else if(max == level) sum += root.val;
        func(root.left, level + 1);
        func(root.right, level + 1);
    }
    public int deepestLeavesSum(TreeNode root) {
        sum = 0;
        max = 0;
        func(root, 0);
        return sum;
    }
}
