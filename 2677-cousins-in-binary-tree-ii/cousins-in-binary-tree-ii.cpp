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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root) return nullptr;
        root->val = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int levelSize = q.size();
            int levelSum = 0;
            vector<TreeNode*> currentLevel;
            // First pass: gather nodes and compute total sum of children
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front(); q.pop();
                currentLevel.push_back(node);

                if (node->left) levelSum += node->left->val;
                if (node->right) levelSum += node->right->val;
            }
            // Second pass: assign cousin sums to children
            for (TreeNode* node : currentLevel) {
                int childSum = 0;
                if (node->left) childSum += node->left->val;
                if (node->right) childSum += node->right->val;
                if (node->left) {
                    node->left->val = levelSum - childSum;
                    q.push(node->left);
                }
                if (node->right) {
                    node->right->val = levelSum - childSum;
                    q.push(node->right);
                }
            }
        }
        return root;
    }
};
