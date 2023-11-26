class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
          int m = mat.size();
        int n = mat[0].size();

        // Function to perform cyclic right shift on a row
        auto cyclicRightShift = [](std::vector<int>& row, int k) {
            rotate(row.rbegin(), row.rbegin() + k % row.size(), row.rend());
        };

        // Function to perform cyclic left shift on a row
        auto cyclicLeftShift = [](std::vector<int>& row, int k) {
            rotate(row.begin(), row.begin() + k % row.size(), row.end());
        };

        // Store the initial matrix for later comparison
        vector<vector<int>> initialMatrix = mat;

        // Perform cyclic shifts on even and odd indexed rows
        for (int i = 0; i < m; ++i) {
            if (i % 2 == 0) 
                cyclicLeftShift(mat[i], k);
            else 
                cyclicRightShift(mat[i], k);
            
        }

        // Check if the final matrix is the same as the initial matrix
        return mat == initialMatrix;
        }
    
};