/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* LCA;
    int pq = 2;
    void searchTree(TreeNode* node, TreeNode* p, TreeNode* q)
    {
        if(pq == 2) LCA = node;
        if(node == p || node == q) --pq;
        if(!pq) return;
        if(node->left != nullptr) searchTree(node->left, p, q);
        if(pq && node->left == LCA) LCA = node;
        if(node->right != nullptr) searchTree(node->right, p, q);
        if(pq && node->right == LCA) LCA = node;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        searchTree(root, p, q);
        return LCA;
    }
};