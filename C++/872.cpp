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
    vector<vector<int>> v = {{}, {}};
    void searchTree(TreeNode* root, int treeId)
    {
        if(root->left == nullptr && root->right == nullptr) v[treeId].emplace_back(root->val);
        if(root->left != nullptr) searchTree(root->left, treeId);
        if(root->right != nullptr) searchTree(root->right, treeId);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        searchTree(root1, 0);
        searchTree(root2, 1);
        return v[0] == v[1];
    }
};