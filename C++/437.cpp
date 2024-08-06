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
    vector<int> path;
    int cnt = 0, idx, tSum;
    long pSum = 0, acc;
    void searchTree(TreeNode* root)
    {
        path.emplace_back(root->val), pSum += root->val, acc = pSum, idx = 0;
        while(idx < path.size())
        {
            if(acc == tSum) ++cnt;
            acc -= path[idx], ++idx;
        }
        if(root->left != nullptr) searchTree(root->left);
        if(root->right != nullptr) searchTree(root->right);
        path.pop_back(), pSum -= root->val;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return 0;
        tSum = targetSum;
        searchTree(root);
        return cnt;
    }
};