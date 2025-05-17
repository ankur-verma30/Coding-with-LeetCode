class Solution {
    void swap(int[] nums, int n1, int n2) {
        int temp = nums[n1];
        nums[n1] = nums[n2];
        nums[n2] = temp;
    }

    public void sortColors(int[] nums) {
        int n = nums.length;
        int zeroIndex = 0, firstIndex = 0, twoIndex = n - 1;

        while (firstIndex <= twoIndex) {
            if (nums[firstIndex] == 0) {
                swap(nums, zeroIndex, firstIndex);
                zeroIndex++;
                firstIndex++;
            } else if (nums[firstIndex] == 1) {
                firstIndex++;
            } else {
                swap(nums, firstIndex, twoIndex);
                twoIndex--;
            }
        }
    }
}