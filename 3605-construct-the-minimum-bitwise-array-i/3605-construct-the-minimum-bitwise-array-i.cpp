class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++) {
            int val = nums[i];
            int j = 0;
            for (int j = 0; j < val; j++) {
                if ((j | (j + 1)) == val) {
                    ans[i] = j;
                    break;
                }
            }
        }
        return ans;
    }
};