class Solution {
public:
     int solve(int eggs,int floors,vector<vector<int>> &dp){
     
        if(floors==0 || floors==1) return floors;
        if(eggs==1) return floors;

        if(dp[eggs][floors]!=-1)  return dp[eggs][floors];

        int ans=INT_MAX,left=1,right=floors;
        while(left<=right){
            int mid=left+(right-left)/2;

            int Isbreak=solve(eggs-1,mid-1,dp);
            int notBreak=solve(eggs,floors-mid,dp);

            int tempAns=1+max(Isbreak,notBreak);

            if(Isbreak<notBreak) left=mid+1;
            else  right=mid-1;
            ans=min(tempAns,ans);
        }
        return dp[eggs][floors]=ans;
    }

    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1));
        return solve(k, n, dp);
    }
};