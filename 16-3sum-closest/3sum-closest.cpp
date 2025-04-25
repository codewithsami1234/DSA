class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
         sort(nums.begin(), nums.end()); // Step 1: Sort the array
    int closestSum = nums[0] + nums[1] + nums[2]; // Initial closest sum

    for (int i = 0; i < nums.size() - 2; ++i) {
        int left = i + 1, right = nums.size() - 1;

        while (left < right) {
            int currentSum = nums[i] + nums[left] + nums[right];

            // Update closest sum if needed
            if (abs(currentSum - target) < abs(closestSum - target)) {
                closestSum = currentSum;
            }

            // Move pointers
            if (currentSum < target) {
                ++left;
            } else {
                --right;
            }
        }
    }
    return closestSum;
}
};