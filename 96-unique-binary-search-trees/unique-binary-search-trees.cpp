class Solution {
public:
    int numTrees(int n) {
        // Base case: empty tree or single node tree
        if (n == 0 || n == 1)
            return 1;
        int total = 0;
        // Try each number from 1 to n as root
        for (int i = 1; i <= n; i++) {
            int left = numTrees(i - 1);      // Left subtree has i-1 nodes
            int right = numTrees(n - i);     // Right subtree has n-i nodes
            total += left * right;           // Total trees = left * right
        }
        return total;
    }
};
