class Solution {
public:
    int longestPalindromeSubseq(string s1) {
        int n = s1.length();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        string s2(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());

        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < n + 1; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                }
            }
        }

        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }

        return dp[n][n];
    }
};