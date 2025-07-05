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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode(0); // dummy node
        TreeNode* curr = dummy; // pointer to build the new tree
        inorder(root, curr);
        return dummy->right; // the real root of the new tree
    }

    void inorder(TreeNode* node, TreeNode*& curr) {
        if (!node) return;

        inorder(node->left, curr);

        node->left = nullptr;     // Remove left child
        curr->right = node;       // Link node to the right of current
        curr = node;              // Move current pointer

        inorder(node->right, curr);
    }
};
