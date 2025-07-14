class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Traverse the tree
        while (root != nullptr) {
            if (p->val < root->val && q->val < root->val) {
                // LCA must be in the left subtree
                root = root->left;
            } 
            else if (p->val > root->val && q->val > root->val) {
                // LCA must be in the right subtree
                root = root->right;
            } 
            else {
                // One node is on the left, the other is on the right
                // or one of them is the root → this is the LCA
                return root;
            }
        }
        return nullptr;
    }
};
