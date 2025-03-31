class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int row = grid.size(),col = grid[0].size();
        vector<int> Grid;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++)
                Grid.push_back(grid[i][j]);
        }

        sort(Grid.begin(), Grid.end());

        int median = (row * col) / 2;
        int val = Grid[median],operations = 0;

        for (int i = 0; i < row * col; i++) {
            int diff = abs(val - Grid[i]);
            if (diff % x != 0)
                return -1;
            operations += diff / x;
        }

        return operations;
    }
};