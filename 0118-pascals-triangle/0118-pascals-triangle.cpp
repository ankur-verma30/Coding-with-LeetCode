class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> dp(numRows);
        dp[0] = {1};

        for (int i = 1; i < numRows; i++) {
            dp[i] = vector<int>(i + 1, -1);
            dp[i][0] = 1;
            for (int j = 1; j < i; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            }
            dp[i][i] = 1;
        }

        return dp;
    }
};