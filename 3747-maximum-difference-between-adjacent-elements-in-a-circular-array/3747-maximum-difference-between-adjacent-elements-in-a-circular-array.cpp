class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxi = INT_MIN, n = nums.size();
        for (int i = 1; i < n; i++) {
            int diff = abs(nums[i] - nums[i - 1]);
            maxi = max(maxi, diff);
        }

        int diff = abs(nums[0] - nums[n - 1]);

        maxi = max(diff, maxi);

        return maxi;
    }
};