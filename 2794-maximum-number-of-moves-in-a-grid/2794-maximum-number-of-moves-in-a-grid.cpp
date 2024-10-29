class Solution {
public:
    int getMaxCount(int row, int col, vector<vector<int>>& grid,vector<vector<int>>&dp) {
        int n = grid.size();
        int m = grid[0].size();
        if ( col >= m)
            return 0;

        int maxi = 0;
        int curr = grid[row][col];
        if(dp[row][col]!=-1) return dp[row][col];

        if (row - 1 >= 0 && col+1 <m && grid[row - 1][col + 1] > curr)
            maxi = 1 + getMaxCount(row - 1, col + 1, grid,dp);

        if (col + 1 < m && grid[row][col + 1] > curr)
            maxi = max(maxi, 1 + getMaxCount(row, col + 1, grid,dp));

        if (row + 1 < n && col + 1 < m && grid[row + 1][col + 1] > curr)
            maxi = max(maxi, 1 + getMaxCount(row + 1, col + 1, grid,dp));

        dp[row][col]=maxi;
        return maxi;
    }
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxCount = 0;

        vector<vector<int>>dp(n,vector<int>(m,-1));
        for (int i = 0; i< n; i++) {
            int count = getMaxCount(i, 0, grid,dp);
             maxCount = max(maxCount, count);
        }

        return maxCount;
    }
};