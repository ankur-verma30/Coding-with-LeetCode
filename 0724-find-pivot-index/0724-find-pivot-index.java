class Solution {
    public int pivotIndex(int[] nums) {
        int n = nums.length;
        int leftSum = 0, totalSum = 0;

        for (int num : nums)
            totalSum += num;

        for (int i = 0; i < n; i++) {
            int rightSum = totalSum - leftSum;
            leftSum += nums[i];
            if (leftSum == rightSum)
                return i;
        }

        return -1;
    }
}