class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        const vector<pair<int, int>> directions = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        queue<pair<int, int>> q;

        dp[0][0] = health - grid[0][0];

        if (dp[0][0] <= 0)
            return false;

        q.push({0, 0});

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (const auto& dir : directions) {
                int nx = x + dir.first;
                int ny = y + dir.second;

                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {

                    int newHealth = dp[x][y] - grid[nx][ny];

                    if (newHealth > 0 && newHealth > dp[nx][ny]) {
                        dp[nx][ny] = newHealth;
                        q.push({nx, ny});
                    }
                }
            }
        }

        return dp[m - 1][n - 1] > 0;
    }
};