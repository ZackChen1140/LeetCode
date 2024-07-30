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
    int goodNum;
    vector<int> path;
    bool greater(int val)
    {
        for(auto& n : path) if(n > val) return false;
        return true;
    }
    void searchTree(TreeNode* root)
    {
        if(greater(root->val)) ++goodNum;
        path.emplace_back(root->val);
        if(root->left != nullptr) searchTree(root->left);
        if(root->right != nullptr) searchTree(root->right);
        path.pop_back();
    }
public:
    int goodNodes(TreeNode* root) {
        searchTree(root);
        return goodNum;
    }
};