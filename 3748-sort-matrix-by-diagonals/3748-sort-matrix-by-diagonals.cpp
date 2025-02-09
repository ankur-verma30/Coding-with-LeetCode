class Solution {
public:
void sortDiagonal(vector<vector<int>>& grid, int row, int col, bool asc) {
        int n = grid.size();
        int len = min(n - row, n - col);
        vector<int> dia(len);

        for (int i = 0; i < len; i++) {
            dia[i] = grid[row + i][col + i];
        }

        sort(dia.begin(), dia.end());
        if (!asc) { 
            reverse(dia.begin(), dia.end());
        }

        for (int i = 0; i < len; i++) {
            grid[row + i][col + i] = dia[i];
        }
    }

    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        for (int i = 0; i < n; i++) {
            sortDiagonal(grid, i, 0, false); 
        }

        for (int j = 1; j < n; j++) {
            sortDiagonal(grid, 0, j, true); 
        }

        return grid;
    }
};