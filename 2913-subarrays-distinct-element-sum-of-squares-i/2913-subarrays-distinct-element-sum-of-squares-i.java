class Solution {
    public int sumCounts(List<Integer> nums) {
        int sum = 0, n = nums.size();

        for (int i = 0; i < n; i++) {
            Set<Integer> st = new HashSet<>();
            for (int j = i; j < n; j++) {
                    st.add(nums.get(j));
                    int count = st.size();
                    sum += (count * count);
            }
        }

        return sum;
    }
}