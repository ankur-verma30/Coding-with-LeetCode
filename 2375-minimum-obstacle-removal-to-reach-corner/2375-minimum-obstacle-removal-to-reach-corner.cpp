class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> minObstacles(row, vector<int>(col, INT_MAX));

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        pq.push({grid[0][0], {0, 0}});
        minObstacles[0][0] = grid[0][0];

        vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!pq.empty()) {
            auto cur = pq.top();
            int obstacles = cur.first;
            int nRow = cur.second.first;
            int nCol = cur.second.second;
            pq.pop();
            if (nRow == row - 1 && nCol == col - 1)
                return obstacles;
            for (auto dir : directions) {
                int newRow = nRow + dir[0], newCol = nCol + dir[1];
                if (newRow >= 0 && newCol >= 0 && newRow < row &&
                    newCol < col) {
                    int newObstacles = obstacles + grid[newRow][newCol];
                    if (minObstacles[newRow][newCol] == INT_MAX) {
                        minObstacles[newRow][newCol] = newObstacles;
                        pq.push({newObstacles, {newRow, newCol}});
                    }
                }
            }
        }
        return -1;
    }
};