class Solution {
public:
    
    int solve(int index,string &s,int n,vector<int>&dp){

        if(dp[index]!=-1) return dp[index];
        if(s[index]=='0') return dp[index]=0;
        if(index==n) return dp[index]=1;

        int singleDigitSplit=solve(index+1,s,n,dp);
        int doubleDigitSplit=0;
        if(index+1<n && (s[index]=='1' || (s[index]=='2' && s[index+1]<='6')))
        doubleDigitSplit=solve(index+2,s,n,dp); 

        return dp[index]=singleDigitSplit+doubleDigitSplit;


    }
    int numDecodings(string s) {
        int n=s.length();
        vector<int>dp(n+1,-1);
        return solve(0,s,n,dp);

    }
};