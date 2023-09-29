class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0; // Initialize count to 0
    int result = 0; // Initialize result to 0
    int len=nums.size();

    for (int i = 0; i < len; i++) {
        if (nums[i] == 1) {
            count++;
            result = max(result, count); // Update result with the maximum count
        } else {
            count = 0; // Reset count when a zero is encountered
        }
    }
    
    return result;
    }
};