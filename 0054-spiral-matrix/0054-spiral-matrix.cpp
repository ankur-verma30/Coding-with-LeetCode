class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();

        int startCol=0,startRow=0;
        int endCol=col-1,endRow=row-1;

        int total=row*col,count=0;
        vector<int>ans;

        while(count<total){

            for(int i=startCol;i<=endCol && count<total;i++){
                ans.push_back(matrix[startRow][i]);
                count++;
            }

            startRow++;

            for(int i=startRow;i<=endRow && count<total ;i++){
                ans.push_back(matrix[i][endCol]);
                count++;
            }
            endCol--;

            for(int i=endCol;i>=startCol && count<total;i--){
                ans.push_back(matrix[endRow][i]);
                count++;
            }
            endRow--;

            for(int i=endRow;i>=startRow && count<total ;i--){
                ans.push_back(matrix[i][startCol]);
                count++;
            }
            startCol++;
        }

        return ans;
    }
};