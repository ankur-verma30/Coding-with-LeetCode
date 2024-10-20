class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxTime = 0;

        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> visited(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    visited[i][j]=2;
                }
            }
        }
        vector<int> delRow{-1, 0, 1, 0};
        vector<int> delCol{0, 1, 0, -1};
        while (!q.empty()) {
            pair<pair<int, int>, int> temp = q.front();
            q.pop();
            int row = temp.first.first;
            int col = temp.first.second;
            int time = temp.second;
            maxTime = max(maxTime, time);
            for (int i = 0; i < 4; i++) {
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                if (nRow >= 0 && nCol >= 0 && nRow < n && nCol < m &&
                    visited[nRow][nCol] != 2 && grid[nRow][nCol] == 1) {
                    visited[nRow][nCol] = 2;
                    q.push({{nRow, nCol}, time + 1});
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && visited[i][j] != 2)
                    return -1;
            }
        }
        return maxTime;
    }
};