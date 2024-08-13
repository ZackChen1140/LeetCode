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
    TreeNode* newSubRoot(TreeNode* sRoot)
    {
        TreeNode* nsRoot;
        nsRoot = sRoot->right == nullptr ? sRoot->left : sRoot->right;
        if(sRoot->right != nullptr)
        {
            TreeNode* rlLeaf = nsRoot;
            while(rlLeaf->left != nullptr) rlLeaf = rlLeaf->left;
            rlLeaf->left = sRoot->left;
        }
        delete sRoot;
        return nsRoot;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key)
    {
        TreeNode* cnode = root, *pnode = nullptr;
        while(cnode != nullptr && cnode->val != key)
            pnode = cnode, cnode = key < cnode->val ? cnode->left : cnode->right;
        if(cnode == nullptr) return root;
        if(pnode == nullptr) root = newSubRoot(cnode);
        else key < pnode->val ? pnode->left = newSubRoot(cnode) : pnode->right = newSubRoot(cnode);
        return root;
    }
};