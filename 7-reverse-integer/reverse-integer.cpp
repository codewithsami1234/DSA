class Solution {
public:
    int reverse(int x) {
        long res = 0;  // Use long to prevent overflow during calculation
        while (x != 0) {
            int lastDigit = x % 10;
            res = res * 10 + lastDigit;
            if (res > INT_MAX || res < INT_MIN) {
                return 0;
            }
            x /= 10;
        }
        return static_cast<int>(res);  // Cast back to int before returning
    }
};
