class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        
        vector<vector<int>> arr2D(m,vector<int>(n));
        int k=0;

        if(m*n!=original.size()) return {};

    // Convert 1D array to 2D array
    for (int i = 0; i <m; ++i) {

        for (int j = 0; j < n; ++j) {
            // Map the 1D index to the 2D indices
            arr2D[i][j] = original[k];
            k++;
        }
    }
    return arr2D;
    }
};