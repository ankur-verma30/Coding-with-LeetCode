class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        if (row == 1)
            return 0;
        int increment = 0;

        for (int j = 0; j < col; j++) {
            int start = grid[0][j];
            for (int i = 1; i < row; i++) {
                int value = grid[i][j];
                if (value > start)
                    start = value;
                else {
                    increment+= (start - value) + 1;
                    start++;
                }
            }
        }

        return increment;
    }
};