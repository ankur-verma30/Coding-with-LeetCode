class Solution {
public:
    bool checkPalindrome(int start, int end, string& s,vector<vector<int>>&dp) {
        if (start >= end)
            return true;

            if(dp[start][end]!=-1) return dp[start][end];
        if (s[start] != s[end]) return dp[start][end]= false;
        return dp[start][end]=checkPalindrome(start + 1, end - 1, s,dp);

    }
    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;

        vector<vector<int>>dp(n,vector<int>(n,-1));

        // dp[i][j]==0 then false
        // dp[i][j]==1 then true
        // dp[i][j]==-1 then not solved

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (checkPalindrome(i, j, s,dp))
                    count++;
            }
        }

        return count;
    }
};