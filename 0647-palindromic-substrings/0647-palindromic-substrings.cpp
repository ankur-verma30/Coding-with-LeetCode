class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();

        vector<vector<int>>dp(n,vector<int>(n,-1));
        int count=0;

        for(int length=1;length<=n;length++){
            for(int start=0;start+length-1<n;start++){
                int end=start+length-1;
                if(start==end) dp[start][end]=1;
                else if(start+1==end && s[start]==s[end]) 
                dp[start][end]=1;
                else {
                    if(s[start]==s[end] && dp[start+1][end-1]==1) 
                    dp[start][end]=1;
                }
                if(dp[start][end]==1) count++;
            }
        }

        return count;
    }
};