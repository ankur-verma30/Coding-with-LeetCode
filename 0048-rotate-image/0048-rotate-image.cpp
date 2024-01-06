class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

    vector<int>results;

    int row=matrix.size();
    int col=matrix[0].size();

    for(int j=0;j<=col-1;j++){
        for(int i=row-1;i>=0;i--){
            results.push_back(matrix[i][j]);
        }
    }

    int k=0;
    
    while(k<results.size()){
        for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            matrix[i][j]=results[k];
            k++;
        }
    }
    }
    }
};