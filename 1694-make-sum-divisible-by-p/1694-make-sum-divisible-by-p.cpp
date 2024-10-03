class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long n = nums.size();
        long long minLen = n, sum = 0, rem = 0;
        for (auto& x : nums)
            sum += x;
        if (sum % p == 0)
            return 0;

        rem = sum % p;

        unordered_map<long long , long long> prefixMod;
        prefixMod[0] = -1;
        long long prefixSum = 0;

        for (int i = 0; i < n; ++i) {
            prefixSum = (prefixSum + nums[i]) % p;
            long long  target = (prefixSum - rem + p) % p;

            if (prefixMod.find(target) != prefixMod.end())
                minLen = min(minLen, i - prefixMod[target]);

            prefixMod[prefixSum] = i;
        }
        return minLen == n ? -1 : minLen;
    }
};