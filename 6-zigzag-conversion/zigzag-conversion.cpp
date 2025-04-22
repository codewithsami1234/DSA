class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) 
            return s;
        
        string result = "";  // Fixed: start with empty string
        int jumps = (numRows - 1) * 2;
        
        for(int i = 0; i < numRows; i++) {
            for(int j = i; j < s.size(); j += jumps) {
                result += s[j];
                
                int diag = j + jumps - 2 * i;
                if(i > 0 && i < numRows - 1 && diag < s.size()) {
                    result += s[diag];
                }
            }
        }
        return result;
    }
};
