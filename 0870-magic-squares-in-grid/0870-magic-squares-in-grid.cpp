class Solution {
public:
    bool magicSquare(vector<vector<int>>& grid, int row, int col) {
        vector<bool> isPresent(10, false);

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int val = grid[row + i][col + j];
                if (val < 1 || val > 9 || isPresent[val])
                    return false;
                isPresent[val] = true;
            }
        }

        // diagonal sum
        int dig1 =
            grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2];
        int dig2 =
            grid[row][col + 2] + grid[row + 1][col + 1] + grid[row + 2][col];

        if (dig1 != dig2)
            return false;

        set<int> Rowst;

        for (int i = row; i < row + 3; i++) {
            int val = 0;
            for (int j = col; j < col + 3; j++) {
                val += grid[i][j];
            }
            Rowst.insert(val);
        }
        if (Rowst.size() > 1)
            return false;

        set<int> Colst;

        for (int j = col; j < col + 3; j++) {
            int val = 0;
            for (int i = row; i < row + 3; i++) {
                val += grid[i][j];
            }
            Colst.insert(val);
        }
        if (Colst.size() > 1)
            return false;

        if (*Rowst.begin() != *Colst.begin())
            return false;

        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        for (int i = 0; i + 2 < rows; i++) {
            for (int j = 0; j + 2 < cols; j++) {
                if (magicSquare(grid, i, j))
                    count++;
            }
        }

        return count;
    }
};