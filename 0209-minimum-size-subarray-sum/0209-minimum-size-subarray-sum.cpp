class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLength = nums.size();
        int left = 0, right = 0;
        int sum = 0;
        bool targetSum = false;

        while (right < nums.size()) {
            sum += nums[right];

            while (sum >= target) {
                minLength = min(minLength, right - left + 1);
                if (sum >= target)
                    targetSum = true;
                sum -= nums[left];
                left++;
            }
            right++;
        }

        return (targetSum) ? minLength : 0;
    }
};