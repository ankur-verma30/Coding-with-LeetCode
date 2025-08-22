class Solution {
    public int pivotIndex(int[] nums) {
         int n = nums.length;
        int[] sum= new int[n];
        int leftSum=0;


        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1) {
               sum[i] = nums[i];
                continue;
            }
           sum[i] =sum[i + 1] + nums[i];
        }

        for (int i = 0; i < n; i++) {
            leftSum+=nums[i];
            if(leftSum==sum[i]) return i;
        }

        return -1;
    }
}