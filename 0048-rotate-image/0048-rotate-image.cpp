class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Step 1: Reverse rows (vertical flip)
        for(int i = 0; i < n/2; i++){
            for(int j = 0; j < n; j++){
                swap(matrix[i][j], matrix[n-i-1][j]);
            }
        }

        // Step 2: Transpose
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
