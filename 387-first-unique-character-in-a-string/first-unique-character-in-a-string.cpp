class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> freq;
        // Count frequencies
        for (char c : s) {
            freq[c]++;
        }
        // Find the first unique character
        for (int i = 0; i < s.length(); i++) {
            if (freq[s[i]] == 1)
                return i;
        }
        return -1; // Moved this line inside the function
    }
};
