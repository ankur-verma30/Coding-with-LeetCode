class Solution {
public:
    int calculateFishes( vector<vector<int>>& grid, vector<vector<bool>>& visited,int r, int c) {
        int row = grid.size();
        int col = grid[0].size();

        if (r < 0 || c < 0 || r >= row || c >= col || visited[r][c] ||
            grid[r][c] == 0) {
            return 0;
        }

        int fishCount = grid[r][c];
        visited[r][c] = true;

        return grid[r][c] + calculateFishes(grid, visited, r, c + 1) +
               calculateFishes(grid, visited, r, c - 1) +
               calculateFishes(grid, visited, r + 1, c) +
               calculateFishes(grid, visited, r - 1, c);
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<bool>> visited(row, vector<bool>(col, false));

        int maxFish = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] > 0 && !visited[i][j]) {
                    int maxi = calculateFishes( grid, visited,i,j);
                    maxFish = max(maxi, maxFish);
                }
            }
        }

        return maxFish;
    }
};