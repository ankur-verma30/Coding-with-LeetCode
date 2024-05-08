class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<int> ans(k + 1, 0);

        int count = 0;
        int val = 0;

        for (int i = nums.size() - 1; i >= 0; i--) {
            if (val == k)
                break;
            if (nums[i] <= k) {
                if (ans[nums[i]] == 0) {
                    ans[nums[i]] = 1;
                    val++;
                }
            }
            count++;
        }

        return count;
    }
};