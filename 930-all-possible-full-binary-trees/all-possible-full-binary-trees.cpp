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
    unordered_map<int, vector<TreeNode*>> memo;

    vector<TreeNode*> allPossibleFBT(int n) {
        if (n % 2 == 0) return {};  // No full binary tree if n is even
        if (n == 1) return {new TreeNode(0)};
        if (memo.count(n)) return memo[n];

        vector<TreeNode*> result;
        for (int leftNodes = 1; leftNodes < n; leftNodes += 2) {
            int rightNodes = n - 1 - leftNodes;
            vector<TreeNode*> leftTrees = allPossibleFBT(leftNodes);
            vector<TreeNode*> rightTrees = allPossibleFBT(rightNodes);
            for (TreeNode* left : leftTrees) {
                for (TreeNode* right : rightTrees) {
                    TreeNode* root = new TreeNode(0);
                    root->left = left;
                    root->right = right;
                    result.push_back(root);
                }
            }
        }
        return memo[n] = result;
    }
};
