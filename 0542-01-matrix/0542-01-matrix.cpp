class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<vector<int>> distance(n, vector<int>(m, 0));
        queue < pair<pair<int, int>, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m;j++) {
                if (mat[i][j] == 0) {
                    visited[i][j] = 1;
                    q.push({{i, j}, 0});
                    distance[i][j] = 0;
                }
            }
        }
        int del[] = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            pair<pair<int, int>, int> temp = q.front();
            int row = temp.first.first;
            int col = temp.first.second;
            int steps = temp.second;
            q.pop();
            distance[row][col] = steps;

            for (int i = 0; i < 4; i++) {
                int nRow = row + del[i];
                int nCol = col + del[i + 1];
                if (nRow >= 0 && nCol >= 0 && nRow < n && nCol < m &&
                    visited[nRow][nCol] != 1) {
                    visited[nRow][nCol] = 1;
                    q.push({{nRow, nCol}, steps + 1});
                }
            }
        }
        return distance;
    }
};