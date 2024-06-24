class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> dp;

        for (int i = 0; i <= rowIndex; i++) {
            vector<int> curr(i + 1, 1);

            for (int j = 1; j < i; j++) {
                curr[j] = dp[j - 1] + dp[j];
            }
            dp = curr;
        }
        return dp;
    }
};