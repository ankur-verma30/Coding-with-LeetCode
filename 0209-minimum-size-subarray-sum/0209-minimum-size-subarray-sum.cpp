class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLength = INT_MAX;
        int left = 0, right = 0;
        int sum = 0;

        while (right < nums.size()) {
            sum += nums[right];

            while (sum >= target) {
                minLength = min(minLength, right - left + 1);
                sum -= nums[left];
                left++;
            }
            right++;
        }

        return (minLength != INT_MAX) ? minLength : 0;
    }
};