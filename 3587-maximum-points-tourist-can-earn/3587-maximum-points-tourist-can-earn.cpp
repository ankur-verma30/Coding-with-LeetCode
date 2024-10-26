class Solution {
public:
    int maxScore(int n, int k, vector<vector<int>>& stayScore,
                 vector<vector<int>>& travelScore) {

        vector<vector<int>> dp(k + 1, vector<int>(n, 0));

        for (int day = 1; day <= k; day++) {
            for (int curr = 0; curr < n; curr++) {
                dp[day][curr] =
                    max(dp[day][curr],
                        dp[day - 1][curr] + stayScore[day - 1][curr]);
                for (int dest = 0; dest < n; dest++) {
                    if (curr != dest) {
                        dp[day][dest] =
                            max(dp[day][dest],
                                dp[day - 1][curr] + travelScore[curr][dest]);
                    }
                }
            }
        }

        int maxPoints = 0;
        for (int city = 0; city < n; city++) {
            maxPoints = max(maxPoints, dp[k][city]);
        }
        return maxPoints;
    }
};