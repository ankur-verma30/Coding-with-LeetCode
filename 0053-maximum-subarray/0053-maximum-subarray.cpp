class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int bestSumTillNow = nums[0], bestSumSoFar = nums[0], n = nums.size();

        for (int i = 1; i < n; i++) {
            bestSumTillNow = max(nums[i], nums[i] + bestSumTillNow);
            bestSumSoFar = max(bestSumTillNow, bestSumSoFar);
        }

        return bestSumSoFar;
    }
};