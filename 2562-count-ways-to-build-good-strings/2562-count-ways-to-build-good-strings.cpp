class Solution {
public:
    int mod = 1e9 + 7;
    int countWays(int low, int high, int zero, int one, int len,
                  vector<int>& dp) {
        if (len > high)
            return 0;
        if (dp[len] != -1)
            return dp[len];
        int ans = (countWays(low, high, zero, one, len + zero, dp) % mod +
                   countWays(low, high, zero, one, len + one, dp) % mod) %
                  mod;
        if (len <= high && len >= low)
            ans += 1;
        return dp[len] = ans % mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, -1);
        return countWays(low, high, zero, one, 0, dp) % mod;
    }
};