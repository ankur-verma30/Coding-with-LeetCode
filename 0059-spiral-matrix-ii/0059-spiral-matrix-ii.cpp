class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int startCol=0,startRow=0;
        int endCol=n-1,endRow=n-1;

        int total=n*n,count=0;
        vector<vector<int>>matrix(n,vector<int>(n,0));

        while(count<total){

            for(int i=startCol;i<=endCol && count<total;i++){
                matrix[startRow][i]=++count;
            }

            startRow++;

            for(int i=startRow;i<=endRow && count<total ;i++){
                matrix[i][endCol]=++count;
        
            }
            endCol--;

            for(int i=endCol;i>=startCol && count<total;i--){
                matrix[endRow][i]=++count;
            }
            endRow--;

            for(int i=endRow;i>=startRow && count<total ;i--){
                matrix[i][startCol]=++count;
            }
            startCol++;
        }

        return matrix;
    }
};
