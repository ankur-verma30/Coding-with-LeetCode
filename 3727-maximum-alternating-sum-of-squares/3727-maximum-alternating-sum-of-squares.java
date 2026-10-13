class Solution {
    public long maxAlternatingSum(int[] nums) {
        int i = 0, j = nums.length - 1;
        long sum = 0;
        boolean isAlternating = true;

        for (int k = 0; k < nums.length; k++) {
            nums[k] = Math.abs(nums[k]);
        }

        Arrays.sort(nums);

        while (i <= j) {
            if (isAlternating) {
                sum += (long) nums[j] * nums[j];
                j--;
            } else {
                sum -= (long) nums[i] * nums[i];
                i++;
            }

            isAlternating = !isAlternating;
        }

        return sum;
    }
}
