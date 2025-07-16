class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int zeros = 0;
        int time = 0;

        for (char c : s) {
            if (c == '0') {
                zeros++;
            } else if (zeros > 0) {
                // each 1 needs to pass over zeros before it
                time = max(time + 1, zeros);
            }
        }

        return time;
    }
};
