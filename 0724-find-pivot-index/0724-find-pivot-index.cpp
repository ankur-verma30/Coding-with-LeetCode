class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int sum[n];
        int leftSum = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1) {
                sum[i] = nums[i];
                continue;
            }
            sum[i] = sum[i + 1] + nums[i];
        }

        for (int i = 0; i < n; i++) {
            leftSum += nums[i];
            if (leftSum == sum[i])
                return i;
        }

        return -1;
    }
};