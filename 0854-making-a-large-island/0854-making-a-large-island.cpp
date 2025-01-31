class Solution {
public:
    int getValue(int row, int col, vector<vector<int>>& grid) {
        return (row < 0 || col < 0 || row >= grid.size() ||
                col >= grid[0].size())
                   ? 0
                   : grid[row][col];
    }

    int fillIsland(int row, int col, int color, vector<vector<int>>& grid) {
        if (getValue(row, col, grid) != 1)
            return 0;
        grid[row][col] = color;
        return 1 + fillIsland(row + 1, col, color, grid) +
               fillIsland(row - 1, col, color, grid) +
               fillIsland(row, col + 1, color, grid) +
               fillIsland(row, col - 1, color, grid);
    }

    int largestIsland(vector<vector<int>>& grid) {
        vector<int> islandSizes = {0, 0};
        int maxSize = 0;

        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[row].size(); ++col) {
                if (grid[row][col] == 1) {
                    islandSizes.push_back(
                        fillIsland(row, col, islandSizes.size(), grid));
                }
            }
        }

        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[row].size(); ++col) {
                if (grid[row][col] == 0) {
                    unordered_set<int> neighboringIslands = {
                        getValue(row + 1, col, grid),
                        getValue(row - 1, col, grid),
                        getValue(row, col + 1, grid),
                        getValue(row, col - 1, grid)};
                    int newSize = 1;
                    for (int color : neighboringIslands) {
                        newSize += islandSizes[color];
                    }
                    maxSize = max(maxSize, newSize);
                }
            }
        }

        return maxSize == 0 ? grid.size() * grid[0].size() : maxSize;
    }
};