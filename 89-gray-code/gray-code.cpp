class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        result.push_back(0);

        for (int i = 0; i < n; ++i) {
            int currentSize = result.size();
            for (int j = currentSize - 1; j >= 0; --j) {
                result.push_back(result[j] | (1 << i));
            }
        }

        return result;
    }
    };
