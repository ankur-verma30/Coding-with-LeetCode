class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int start = 0, end = 0, curMin = INT_MAX, curMax = INT_MIN;
        long count = 0;
        int n = nums.size();
        while (end < n) {
            curMin = min(curMin, nums[end]);
            curMax = max(curMax, nums[end]);
            if (curMax - curMin > 2) {
                start = end;
                curMin = nums[end];
                curMax = nums[end];
                while (start - 1 >= 0 &&
                       abs(nums[start - 1] - nums[end]) <= 2) {
                    start--;
                    curMin = min(curMin, nums[start]);
                    curMax = max(curMax, nums[start]);
                }
            }
            count += (end - start + 1);
            end++;
        }
        return count;
    }
};