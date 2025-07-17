
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
class CBTInserter {
private:
    TreeNode* root;
    queue<TreeNode*> q;  // nodes that are missing at least one child

public:
    CBTInserter(TreeNode* root) {
        this->root = root;
        queue<TreeNode*> temp;
        temp.push(root);
        // level order traversal
        while (!temp.empty()) {
            TreeNode* node = temp.front();
            temp.pop();
            if (!(node->left && node->right)) {
                q.push(node);  // node not full
            }
            if (node->left)  temp.push(node->left);
            if (node->right) temp.push(node->right);  // <-- semicolon fixed
        }
    }
    
    int insert(int val) {
        TreeNode* parent = q.front();
        TreeNode* newNode = new TreeNode(val);
        if (!parent->left) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
            q.pop();  // parent now full
        }
        q.push(newNode);  // new node is a future parent candidate
        return parent->val;
    }
    
    TreeNode* get_root() {
        return root;
    }
};
