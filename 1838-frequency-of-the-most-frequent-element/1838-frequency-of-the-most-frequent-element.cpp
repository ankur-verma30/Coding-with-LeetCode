class Solution {
public:
    int BSearch(vector<long long>& prefixSum, vector<int>& nums, int k,
                int targetIndex) {
        int low = 0, high = targetIndex, ans = targetIndex;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int count = targetIndex - mid + 1;
            long long windowSum = 1LL*nums[targetIndex] * count;
            long long originalSum =
                prefixSum[targetIndex] - prefixSum[mid] + nums[mid];
            if (windowSum - originalSum > k)
                low = mid + 1;
            else {
                ans = mid;
                high = mid - 1;
            }
        }

        return targetIndex - ans + 1;
    }
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size(), maxLen = 0;

        vector<long long> prefixSum(n, 0);
        prefixSum[0] = nums[0];

        for (int i = 1; i < n; i++)
            prefixSum[i] = prefixSum[i - 1] + nums[i];

        for (int right = 0; right < n; right++) {
            int freq = BSearch(prefixSum, nums, k, right);
            maxLen = max(maxLen, freq);
        }

        return maxLen;
    }
};