class Solution {
public:
    int minInsertions(string s) {
        int n=s.length();
        string revS(s.begin(),s.end());

        reverse(revS.begin(),revS.end());
        
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    
        for(int i=1;i<n+1;i++){
            for(int j=1;j<n+1;j++){
                if(s[i-1]==revS[j-1]) {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        return n-dp[n][n]; 
    }
};