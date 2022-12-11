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
   public int maxPathSum(TreeNode root) {
       int[] arr = new int[1];
       arr[0] = Integer.MIN_VALUE; 
       maxPathS(root,arr);
       return arr[0]; 
    }
    
    public int maxPathS(TreeNode root,int[] arr)
    {
        if(root ==null)
            return 0;
        
        int leftSum = Math.max(0,maxPathS(root.left, arr));
        int rightSum = Math.max(0,maxPathS(root.right, arr));
        arr[0] = Math.max(arr[0], leftSum + rightSum + root.val);
        
        return Math.max(leftSum,rightSum) + root.val;
    }
}