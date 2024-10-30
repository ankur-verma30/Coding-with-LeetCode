class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftLIS(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j])
                    leftLIS[i] = max(leftLIS[i], leftLIS[j] + 1);
            }
        }
        vector<int> rightLDS(n, 1);
        for (int i = n - 2; i >= 0; i--) {
            for (int j = n - 1; j > i; j--) {
                if (nums[i] > nums[j])
                    rightLDS[i] = max(rightLDS[i], rightLDS[j] + 1);
            }
        }
        int maxLength = 0;
        for (int i = 1; i < n - 1; i++) {
            if (leftLIS[i] > 1 && rightLDS[i] > 1)
                maxLength =
                    max(maxLength, leftLIS[i] + rightLDS[i] - 1);
        }

        return n - maxLength;
    }
};