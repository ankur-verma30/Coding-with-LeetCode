class Solution {
    public int pivotIndex(int[] nums) {
         int n = nums.length;
        int[] leftSum= new int[n];
        int[] rightSum=new int[n];

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                leftSum[i] = nums[i];
                continue;
            }
            leftSum[i] = leftSum[i - 1] + nums[i];
        }

        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1) {
                rightSum[i] = nums[i];
                continue;
            }
            rightSum[i] = rightSum[i + 1] + nums[i];
        }

        for (int i = 0; i < n; i++) {
            if (leftSum[i] == rightSum[i])
                return i;
        }

        return -1;
    }
}