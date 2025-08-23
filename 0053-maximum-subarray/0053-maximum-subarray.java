class Solution {
    public int maxSubArray(int[] nums) {
        int bestSumTillNow = nums[0], bestSumSoFar = nums[0], n = nums.length;

        for (int i = 1; i < n; i++) {
            bestSumTillNow = Math.max(nums[i], nums[i] + bestSumTillNow);
            bestSumSoFar = Math.max(bestSumTillNow, bestSumSoFar);
        }

        return bestSumSoFar;
    }
}