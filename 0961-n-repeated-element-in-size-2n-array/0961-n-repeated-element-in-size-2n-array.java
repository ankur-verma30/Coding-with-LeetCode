class Solution {
    public int repeatedNTimes(int[] nums) {
        int n=nums.length;
        Set<Integer> st = new HashSet<>();

        for (int i = 0; i < n; i++) {
            if (st.contains(nums[i]))
                return nums[i];
            st.add(nums[i]);
        }

        return -1;
    }
}