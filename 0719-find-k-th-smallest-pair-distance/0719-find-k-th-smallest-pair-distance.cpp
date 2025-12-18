class Solution {
public:
    int slidingWindow(vector<int>& nums, int distance) {
        int left = 0, n = nums.size();

        int pairCount = 0;
        for (int right = 1; right < n; right++) {
                while(nums[right] - nums[left] > distance) left++;
                 pairCount+=(right-left);
        }

        return pairCount;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        sort(nums.begin(), nums.end());

        int low = 0, high = nums[n - 1] - nums[0];

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int pairCount = slidingWindow(nums, mid);
            if (pairCount >= k) {
                ans = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }

        return ans;
    }
};