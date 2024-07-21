class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int n = nums.size();
        vector<int> OneOp(k + 1, 0);

        for (int i = 0; i < n / 2; i++) {
            int diff = abs(nums[i] - nums[n - i - 1]);
            mpp[diff]++;

            int minEle = min(nums[i], nums[n - i - 1]);
            int maxEle = max(nums[i], nums[n - i - 1]);
            int maxAchive = max(k - minEle, maxEle - 0);
            OneOp[maxAchive]++;
        }

        // Prefix Sum
        for (int maxAchieve = k - 1; maxAchieve >= 0; maxAchieve--) {
            OneOp[maxAchieve] += OneOp[maxAchieve + 1];
        }

        int ans = INT_MAX;

        for (auto& [digit, freq] : mpp) {
            int oneExtra = OneOp[digit] - freq;
            int two = n / 2 - oneExtra - freq;
            ans = min(ans, oneExtra + (two) * 2);
        }

        return ans;
    }
};