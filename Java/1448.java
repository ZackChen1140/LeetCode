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
    private int goodNum;
    private ArrayList<Integer> path = new ArrayList<Integer>();
    private boolean greater(int val)
    {
        for(int i = 0; i < path.size(); ++i) if(path.get(i) > val) return false;
        return true;
    }
    private void searchTree(TreeNode node)
    {
        if(greater(node.val)) ++goodNum;
        path.add(node.val);
        if(node.left != null) searchTree(node.left);
        if(node.right != null) searchTree(node.right);
        path.remove(path.size() - 1);
    }
    public int goodNodes(TreeNode root) {
        searchTree(root);
        return goodNum;
    }
}