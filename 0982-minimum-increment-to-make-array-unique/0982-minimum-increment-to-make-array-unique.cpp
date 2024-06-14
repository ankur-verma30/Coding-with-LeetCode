class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        bool flag = true;
        sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] == nums[i])
                flag = false;
        }

        if (flag)
            return 0;

        int ans = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i - 1]) {
                ans += (nums[i - 1] - nums[i]) + 1;
                nums[i] += (nums[i - 1] - nums[i]) + 1;
            }
        }

        return ans;
    }
};