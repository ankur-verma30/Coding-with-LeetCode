class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vector<vector<int>>ans;
        int row=grid.size(),col=grid[0].size();

        vector<pair<int,int>>rows,cols;
        //ones and zeores

        for(int i=0;i<row;i++){
            int oneCount=0,zeroCount=0;
            for(int j=0;j<col;j++){
                (grid[i][j]==1) ? oneCount++ : zeroCount++; 
            }
            rows.push_back({oneCount,zeroCount});
        }

         for(int j=0;j<col;j++){
            int oneCount=0,zeroCount=0;
            for(int i=0;i<row;i++){
                (grid[i][j]==1) ? oneCount++ : zeroCount++; 
            }
            cols.push_back({oneCount,zeroCount});
        }

        for(int i=0;i<row;i++){
            vector<int>temp;
            for(int j=0;j<col;j++){
             auto rowsVal=rows[i];
             int rowOnes=rowsVal.first,rowZeroes=rowsVal.second;

             auto colsVal=cols[j];
             int colsOnes=colsVal.first,colsZeroes=colsVal.second;

             int diff=rowOnes+colsOnes-rowZeroes-colsZeroes;
             temp.push_back(diff);
            }
            ans.push_back(temp);
        }

        return ans;
        
    }
};