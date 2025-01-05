class Solution {
public:
    int maxLength(vector<int>& nums) {
        int maxLen = 0, n = nums.size();

        for (int i = 0; i < n; i++) {
            long long prod = 1;
            int GCD = nums[i];
            int LCM = nums[i];
            for (int j = i; j < n; j++) {
                GCD = __gcd(nums[j], GCD);
                if (prod > LLONG_MAX / nums[j]) break;
                prod *= (long long)nums[j];
               
                LCM = lcm(LCM, nums[j]);
                if (prod == static_cast<long long>(LCM) * GCD)
                    maxLen = max(maxLen, j - i + 1);
            }
        }

        return maxLen;
    }
};