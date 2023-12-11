class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int a=matrix.size();
        int b=matrix[0].size();

        vector<vector<int>>result(b,vector<int>(a,0));

        for(int i=0;i<b;i++){
            for(int j=0;j<a;j++){
               result[i][j]=matrix[j][i];
            }
        }
        return result;
    }
};