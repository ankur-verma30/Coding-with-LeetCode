class Solution {
public:
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
    const int MOD=1e9+7;
       int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(16, 0)));  

        dp[0][0][grid[0][0]]=1;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int xorVal=0;xorVal<16;xorVal++){
                    if(dp[i][j][xorVal]>0){
                        if(j+1<m){
                            int newXor=xorVal^grid[i][j+1];
                            dp[i][j+1][newXor]=(dp[i][j+1][newXor]+dp[i][j][xorVal])%MOD;
                        }
                        if(i+1<n){
                            int newXor=xorVal^grid[i+1][j];
                            dp[i+1][j][newXor]=(dp[i+1][j][newXor]+dp[i][j][xorVal])%MOD;
                        }
                    }
                }
            }
        }
        return dp[n-1][m-1][k];
    }
};