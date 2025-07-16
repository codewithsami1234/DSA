class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int evenCount = 0, oddCount = 0;
        int alt1 = 0, alt2 = 0;

        for (int x : nums) {
            if (x % 2 == 0) {
                evenCount++;
                alt1 = max(alt1, alt2 + 1);  // ending with even
            } else {
                oddCount++;
                alt2 = max(alt2, alt1 + 1);  // ending with odd
            }
        }

        return max({evenCount, oddCount, alt1, alt2});
    }
};
