class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int count = 1;

        int starting_row = 0, starting_col = 0, ending_row = n - 1,
            ending_col = n - 1;

        while (count <= n * n) {
            for (int index = starting_col;
                 count <= n * n && index <= ending_col; index++) {
                ans[starting_row][index] = count++;
            }
            starting_row++;

            for (int index = starting_row; count <= n * n && index <= ending_row;
                 index++) {
                ans[index][ending_col] = count++;
            }
            ending_col--;

            for (int index = ending_col; count <= n * n && index >= starting_col;
                 index--) {
                ans[ending_row][index] = count++;
            }
            ending_row--;

            for (int index = ending_row; count <= n * n && index >= starting_row;
                 index--) {
                ans[index][starting_col] = count++;
            }
            starting_col++;
        }
        return ans;
    }
};