class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {

        int row=mat.size();
        int col=mat[0].size();

        int count=0,RowIndex=0;
        int result=0;

        for(int i=0;i<row;i++){
            count=0;
            for(int j=0;j<col;j++){
                if(mat[i][j]==1)  count++;
            }
            if(count>result){
                result=count;
                RowIndex=i;
            }
        }

        return {RowIndex,result};
        
    }
};