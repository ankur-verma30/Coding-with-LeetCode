class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        set<int> st;

        for (int day : days)
            st.insert(day);

        int lastDay = days[days.size() - 1] + 30;
        vector<int> dp(lastDay + 1);

        for (int day = days[days.size() - 1]; day >= 0; day--) {
            if (!st.count(day)) {
                dp[day] = dp[day + 1];
                continue;
            }
            int oneDay = costs[0] + dp[day + 1];
            int sevenDay = costs[1] + dp[day + 7];
            int thirtyDay = costs[2] + dp[day + 30];
            dp[day] = min(oneDay, min(sevenDay, thirtyDay));
        }
        return dp[days[0]];
    }
};