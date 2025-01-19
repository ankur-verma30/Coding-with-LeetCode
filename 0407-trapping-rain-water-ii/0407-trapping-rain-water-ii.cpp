class Solution {
public:
 bool isValidCell(int row, int col, int rows, int cols) {
        return row >= 0 && col >= 0 && row < rows && col < cols;
    }
    int trapRainWater(vector<vector<int>>& heightMap) {
        vector<vector<int>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        int rows = heightMap.size();
        int cols = heightMap[0].size();
        if (rows < 3 || cols < 3) return 0;

        int totalUnvisitedCells = rows * cols;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        for (int i = 0; i < rows; i++) {
            pq.push({heightMap[i][0], i, 0});
            pq.push({heightMap[i][cols - 1], i, cols - 1});
            visited[i][0] = true;
            visited[i][cols - 1] = true;
            totalUnvisitedCells -= 2;
        }

        for (int i = 1; i < cols - 1; i++) {
            pq.push({heightMap[0][i], 0, i});
            pq.push({heightMap[rows - 1][i], rows - 1, i});
            visited[0][i] = true;
            visited[rows - 1][i] = true;
            totalUnvisitedCells -= 2;
        }

        int trappedWater = 0;
        int waterLevel = 0;

        while (!pq.empty() && totalUnvisitedCells > 0) {
            vector<int> currentCell = pq.top();
            pq.pop();
            int currentHeight = currentCell[0];
            int currentRow = currentCell[1];
            int currentCol = currentCell[2];
            waterLevel = max(waterLevel, currentHeight);

            for (const auto& d : dir) {
                int neighborRow = currentRow + d[0];
                int neighborCol = currentCol + d[1];
                if (isValidCell(neighborRow, neighborCol, rows, cols) && !visited[neighborRow][neighborCol]) {
                    int neighborHeight = heightMap[neighborRow][neighborCol];
                    if (neighborHeight < waterLevel) {
                        trappedWater += waterLevel - neighborHeight;
                    }
                    pq.push({neighborHeight, neighborRow, neighborCol});
                    visited[neighborRow][neighborCol] = true;
                    totalUnvisitedCells--;
                }
            }
        }
        return trappedWater;
    }
};