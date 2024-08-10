/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int pathSize, maxSize = 0;
    void searchTree(TreeNode* root, int lastDire)
    {
        TreeNode* nextNodes[2] = {root->right, root->left};
        int revDire = (lastDire + 1) % 2;
        if(nextNodes[lastDire] != nullptr) ++pathSize, searchTree(nextNodes[lastDire], revDire);
        else if(pathSize > maxSize) maxSize = pathSize;
        if(nextNodes[revDire] != nullptr) pathSize = 1, searchTree(nextNodes[revDire], lastDire);
    }
public:
    int longestZigZag(TreeNode* root) 
    {
        if(root == nullptr) return 0;
        pathSize = 0, searchTree(root, 1);
        return maxSize;
    }
};