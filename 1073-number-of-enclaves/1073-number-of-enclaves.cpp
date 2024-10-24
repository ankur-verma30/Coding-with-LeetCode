class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& grid,
             vector<vector<int>>& visited, int del[]) {
        visited[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < 4; i++) {
            int nRow = row + del[i];
            int nCol = col + del[i + 1];
            if (nRow >= 0 && nCol >= 0 && nRow < n && nCol < m &&
                grid[nRow][nCol] == 1 && visited[nRow][nCol] != 1)
                dfs(nRow, nCol, grid, visited, del);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));

        int del[] = {-1, 0, 1, 0, -1};
        // traverse through columns
        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 1)
                dfs(0, j, grid, visited, del);
            if (grid[n - 1][j] == 1)
                dfs(n-1, j, grid, visited, del);
        }

        // traverse through rows
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1)
                dfs(i, 0, grid, visited, del);
            if (grid[i][m - 1] == 1)
                dfs(i, m - 1, grid, visited, del);
        }
        int count=0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && visited[i][j] != 1)
                    count++;
            }
        }
        return count;
    }
};