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
    vector<int> ans;
    int maxLayer = 0;
    void searchTree(TreeNode* node, int layer)
    {
        if(layer > maxLayer) maxLayer = layer, ans.emplace_back(node->val);
        if(node->right != nullptr) searchTree(node->right, layer + 1);
        if(node->left != nullptr) searchTree(node->left, layer + 1);
    }
public:
    vector<int> rightSideView(TreeNode* root) 
    {
        if(root == nullptr) return ans;
        searchTree(root, 1);
        return ans;
    }
};