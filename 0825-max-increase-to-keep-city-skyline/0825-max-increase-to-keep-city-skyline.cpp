class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
       int row=grid.size(), col=grid[0].size(),ans=0;

       vector<int>rowMax(row),colMax(col);

       for(int i=0;i<row;i++){
        rowMax[i]=*max_element(grid[i].begin(),grid[i].end());
       }

       for(int i=0;i<col;i++){
        int maxElement=0;
        for(int j=0;j<row;j++){
            maxElement=max(maxElement,grid[j][i]);
        }
        colMax[i]=maxElement;
       }

       for(int i=0;i<row;i++){
        int rowVal=rowMax[i];
        for(int j=0;j<col;j++){
            int colVal=colMax[j];
            int minVal=min(rowVal,colVal);
            ans+=(minVal-grid[i][j]);
        }
       }
       return ans;

    }
};