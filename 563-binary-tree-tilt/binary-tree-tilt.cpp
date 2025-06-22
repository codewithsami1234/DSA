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
 int totalTilt = 0;
 int computeSubtreeSum(TreeNode *node){
    if(!node) return 0;
    int leftSum = computeSubtreeSum(node->left);
    int rightSum = computeSubtreeSum(node->right);
    
    //calculate tilt from current node
    int tilt = abs(leftSum- rightSum);
    totalTilt += tilt;

    // return total sum of subtree
    return leftSum +rightSum +node->val;
 }
    int findTilt(TreeNode* root) {
        computeSubtreeSum(root);
        return totalTilt;
    }
};