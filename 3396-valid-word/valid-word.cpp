class Solution {
public:
    bool isValid(string word) {
        if (word.length() < 3) {
            return false;
        }
        bool hasConsonant = false;
        bool hasVowel = false;
        for (char ch : word) {
            if (!isalnum(ch))
                return false;

            if (isalpha(ch)) {
                char lower = tolower(ch);
                if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
                    hasVowel = true;
                } else {
                    hasConsonant = true;
                }
            }
        }
        return hasVowel && hasConsonant;
    }
};
