class Solution {
public:
    void solve(int index, vector<int>& nums, int n, int& count, vector<int> ds,
               int maxOr) {
        if (index == n) {
            int maxi = 0;
            for (int i = 0; i < ds.size(); i++)
                maxi |= ds[i];
            if (maxi == maxOr)
                count++;
            return;
        }
        ds.push_back(nums[index]);
        solve(index + 1, nums, n, count, ds, maxOr);
        ds.pop_back();
        solve(index + 1, nums, n, count, ds, maxOr);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            maxOr = maxOr | nums[i];
        }
        int count = 0;
        vector<int> ds;
        solve(0, nums, n, count, ds, maxOr);
        return count;
    }
};