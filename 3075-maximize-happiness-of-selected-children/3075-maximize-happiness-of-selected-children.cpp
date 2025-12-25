class Solution {
public:
    long long maximumHappinessSum(vector<int>& nums, int k) {
        long long totalHappiness = 0;
        int n = nums.size();

        sort(nums.rbegin(), nums.rend());

        int count = 0;
        for (int i = 0; i < k; i++) {
            if (i == 0){
                totalHappiness += nums[i];
                continue;
            }
            count++;
            long long value = (nums[i] - count > 0) ? nums[i] - count : 0;
            totalHappiness += value;
        }

        return totalHappiness;
    }
};
