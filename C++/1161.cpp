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
    vector<int> layerSum;
    void searchTree(TreeNode* node, int layer)
    {
        if(node == nullptr) return;
        if(layerSum.size() < layer) layerSum.emplace_back(node->val);
        else layerSum[layer - 1] += node->val;
        searchTree(node->left, layer + 1);
        searchTree(node->right, layer + 1);
    }
public:
    int maxLevelSum(TreeNode* root)
    {
        searchTree(root, 1);
        return max_element(layerSum.begin(), layerSum.end()) - layerSum.begin() + 1;
    }
};