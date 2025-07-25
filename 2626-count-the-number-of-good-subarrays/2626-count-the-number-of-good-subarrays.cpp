class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        int n = nums.size(), right = 0, left = 0, pairCount = 0;
        long long ans = 0;

        for (int right = 0; right < n; right++) {
            pairCount += mp[nums[right]];
            mp[nums[right]]++;

            while (pairCount >= k) {
                ans += (n - right);
                mp[nums[left]]--;
                pairCount -= mp[nums[left]];
                left++;
            }
        }

        return ans;
    }
};