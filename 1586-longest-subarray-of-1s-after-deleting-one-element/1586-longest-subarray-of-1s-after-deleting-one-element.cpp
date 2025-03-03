class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(), left = 0, zeroCount = 0;

        int maxLength = 0;
        for (int right = 0; right < n; right++) {
            if (nums[right] == 0)
                zeroCount++;
            if (zeroCount <= 1) {
                maxLength = max(maxLength, right - left + 1);
            } else if (zeroCount >= 2) {
                while (zeroCount >= 2) {
                    if (nums[left] == 0)
                        zeroCount--;
                    left++;
                }
            }
        }
        return maxLength - 1;
    }
};