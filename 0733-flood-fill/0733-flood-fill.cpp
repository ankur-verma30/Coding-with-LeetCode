class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& ans,
             vector<vector<int>>& image, int initial, int color,
             vector<int>& rowArray, vector<int>& colArray) {
        int rowSize = image.size();
        int colSize = image[0].size();
        ans[row][col] = color;

        for (int i = 0; i < 4; i++) {
            int nRow = row + rowArray[i];
            int nCol = col + colArray[i];
            if (nRow >= 0 && nRow < rowSize && nCol >= 0 && nCol < colSize &&
                image[nRow][nCol] == initial && ans[nRow][nCol] != color) {
                dfs(nRow, nCol, ans, image, initial, color, rowArray, colArray);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int initial = image[sr][sc];
        vector<vector<int>> ans = image;

        vector<int> rowArray{-1, 0, 1, 0};
        vector<int> colArray{0, 1, 0, -1};
        dfs(sr, sc, ans, image, initial, color, rowArray, colArray);

        return ans;
    }
};