class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, sum = 0, n = nums.size(), minLen = n+1;

        for (int right = 0; right < n; right++) {
            sum += nums[right];
            if (sum >= target) {
                minLen = min(minLen, right - left + 1);
                while (left < n && sum >= target) {
                    minLen = min(minLen, right - left + 1);
                    sum -= nums[left++];
                }
            }
        }
        return minLen==n+1 ? 0 :minLen;
    }
};