class Solution {
    public int majorityElement(int[] nums) {
        int count = 0, element = 0, n = nums.length;

        for (int num : nums) {
            if (count == 0) {
                element = num;
                count = 1;
            } else if (count > 0 && element == num)
                count++;
            else
                count--;
        }

        return element;
    }
}