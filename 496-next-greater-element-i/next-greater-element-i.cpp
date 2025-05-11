
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        stack<int> st;
        // Traverse nums2 and build the map
        for (int num : nums2) {
            while (!st.empty() && num > st.top()) {
                nextGreater[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }
        // Remaining elements in stack have no next greater element
        while (!st.empty()) {
            nextGreater[st.top()] = -1;
            st.pop();
        }
        // Build result using nums1
        vector<int> result;
        for (int num : nums1) {
            result.push_back(nextGreater[num]);
        }
        return result;
    }
};
