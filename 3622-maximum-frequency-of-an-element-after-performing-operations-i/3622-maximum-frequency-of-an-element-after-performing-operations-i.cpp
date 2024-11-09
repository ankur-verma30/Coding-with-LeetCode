class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        int size = maxi + k + 2;
        vector<int> freq(size, 0);

        for (const auto& num : nums)
            freq[num] += 1;

        vector<int> pre(size, 0);
        pre[0] = freq[0];

        for (int i = 1; i < size; i++) {
            pre[i] = pre[i - 1] + freq[i];
        }

        int res = 0;

        for (int i = 0; i < size; i++) {
            if (freq[i] == 0 && numOperations == 0)
                continue;
            int left = max(0, i - k);
            int right = min(size - 1, i + k);
            int range = pre[right] - (left > 0 ? pre[left - 1] : 0);
            int canAdjust = range - freq[i];
            int total = freq[i] + min(numOperations, canAdjust);

            res = max(res, total);
        }

        return res;
    }
};