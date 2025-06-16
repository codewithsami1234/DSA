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
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr)
        return nullptr;
        // recursively invert left and right subtree
        TreeNode *leftSubTree = invertTree(root->left);
        TreeNode *rightSubTree = invertTree(root->right);
        root->left = rightSubTree;
        root->right = leftSubTree; 
        return root;
    }
};