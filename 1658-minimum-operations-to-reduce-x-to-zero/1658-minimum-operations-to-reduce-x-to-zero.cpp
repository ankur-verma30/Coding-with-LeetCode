class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), left = 0, maxLen = INT_MIN, sum = 0;

        for (const int num : nums)
            sum += num;
        if (sum < x)
            return -1;
        if (sum == x)
            return n;

        int target = sum - x;
        int currSum = 0;
        for (int right = 0;right < n; right++) {
            currSum += nums[right];
             while (currSum > target)  currSum -= nums[left++];
            if (currSum == target)  maxLen = max(maxLen, right - left + 1);
            
        }
        return maxLen == INT_MIN ? -1 : n - maxLen;
    }
};