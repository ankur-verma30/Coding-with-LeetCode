class Solution {
    public int subarraySum(int[] nums, int k) {
         HashMap<Integer,Integer> sumPrefix=new HashMap<>();
        int ans = 0, sum = 0, n = nums.length;
        sumPrefix.put(0,0);

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (sum == k)
                ans++;
            if (sumPrefix.containsKey(sum - k)) {
                int value=sumPrefix.get(sum-k);
                ans+=value;
            }
           sumPrefix.put(sum,sumPrefix.getOrDefault(sum, 0) + 1);
        }
        return ans;
    }
}