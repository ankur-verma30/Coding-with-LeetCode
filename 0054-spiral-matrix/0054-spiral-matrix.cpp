class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int row=matrix.size();
        int col=matrix[0].size();

        int count=0;
        int total=row*col;

        vector<int>result;

        int starting_row=0;
        int starting_col=0;
        int ending_row=row-1;
        int ending_col=col-1;

        while(count<total){
//printing starting row
        for(int index=starting_col;count<total && index<=ending_col;index++){
            result.push_back(matrix[starting_row][index]);
            count++;
        }
        starting_row++;

        //printing ending column

        for(int index=starting_row;count<total && index<=ending_row;index++){
            result.push_back(matrix[index][ending_col]);
            count++;
        }
        ending_col--;

        //printing ending row

        for(int index=ending_col;count<total && index>=starting_col;index--){
            result.push_back(matrix[ending_row][index]);
            count++;
        }
        ending_row--;

        //printing starting col

        for(int index=ending_row;count<total && index>=starting_row;index--){
            result.push_back(matrix[index][starting_col]);
            count++;
        }
        starting_col++;
        }
        return result;
    }
};