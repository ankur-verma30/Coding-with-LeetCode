class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int flipCountCol=0;
        int row=grid.size();
        int col=grid[0].size();

        for(int i=0;i<row;i++){
            for(int j=0;j<col/2;j++){
                if(grid[i][j]!=grid[i][col-j-1]) flipCountCol++;
            }
        }
        int flipCountRow=0;
        for(int j=0;j<col;j++){
            for(int i=0;i<row/2;i++){
                if(grid[i][j]!=grid[row-i-1][j]) flipCountRow++;
            }
        }

        return min(flipCountCol,flipCountRow);
    }
};