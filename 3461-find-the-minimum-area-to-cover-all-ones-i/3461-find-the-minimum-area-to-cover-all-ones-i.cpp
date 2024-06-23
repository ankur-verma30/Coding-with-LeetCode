class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
          int minRow = grid.size(), maxRow = -1;
    int minCol = grid[0].size(), maxCol = -1;
    
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 1) {
                minCol = min(minCol, j);
                maxCol = max(maxCol, j);
                minRow = min(minRow, i);
                maxRow = max(maxRow, i);
               
            }
        }
    }
    
  
    int len = (maxRow - minRow) + 1;
    int wid = (maxCol - minCol) + 1;
    
    return len * wid;

    }
};