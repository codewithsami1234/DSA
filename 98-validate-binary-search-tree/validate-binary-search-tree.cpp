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
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
    private:
    bool helper(TreeNode *node, long lower , long upper){
        if(!node ) return true;
        if(node->val <= lower || node->val >= upper)
        return false ;
        return helper(node->left , lower, node->val) && 
        helper(node->right ,node ->val , upper);
    }
};