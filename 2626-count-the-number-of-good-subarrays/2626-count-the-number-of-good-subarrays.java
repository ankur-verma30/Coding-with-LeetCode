import java.util.HashMap;

class Solution {
    public long countGood(int[] nums, int k) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int n = nums.length, left = 0;
        long ans = 0, pairCount = 0;

        for (int right = 0; right < n; right++) {
            int val = nums[right];
            int freq = map.getOrDefault(val, 0);
            pairCount += freq;
            map.put(val, freq + 1);

            while (pairCount >= k) {
                ans += (n - right);
                int leftVal = nums[left];
                int leftFreq = map.get(leftVal);
                map.put(leftVal, leftFreq - 1);
                pairCount -= leftFreq - 1;
                left++;
            }
        }

        return ans;
    }
}
