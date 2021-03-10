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
    
    public void solve(TreeNode root, int v, int d){
        if(d==2){  //target node
    		//left
            TreeNode leftSub = new TreeNode(v);
            leftSub.left = root.left;
            root.left = leftSub;
            //right
            TreeNode rightSub = new TreeNode(v);
    		rightSub.right = root.right;
    		root.right = rightSub;

    		 return;
    	 }
    	 if(root.left!=null)
    		 solve(root.left, v, d-1);
    	 if(root.right!=null)
    		 solve(root.right, v, d-1);    
    }
        
    public TreeNode addOneRow(TreeNode root, int v, int d) {
       if(d==1){
           TreeNode tmpNode = new TreeNode(v,root, null);
           root = tmpNode;
       }
       else{
            solve(root, v, d);
       }
       return root;
    }
}