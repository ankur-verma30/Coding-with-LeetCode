class Solution {
public:
    long long maximumHappinessSum(vector<int>& nums, int k) {
        long long totalHappiness = 0;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int count = 0;
        for (int i = n-1; i >= n-k; i--) {
            long long value = (nums[i] - count > 0) ? nums[i] - count : 0;
            count++;
            totalHappiness += value;
        }

        return totalHappiness;
    }
};
