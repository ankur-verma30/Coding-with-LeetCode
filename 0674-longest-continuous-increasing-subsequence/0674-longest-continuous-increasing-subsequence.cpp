class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
         if (nums.empty()) return 0; // Handle empty input case

    int maxLen = 1; // Initialize the maximum length to 1 (minimum possible)

    int currentLen = 1; // Initialize the current length to 1
    
    for (int i = 0; i < nums.size() - 1; i++) {
        if (nums[i] < nums[i + 1]) {
            currentLen++;
            maxLen = max(maxLen, currentLen); // Update the maximum length
        } else {
            currentLen = 1; // Reset the current length
        }
    }
    
    return maxLen;
    }
};
