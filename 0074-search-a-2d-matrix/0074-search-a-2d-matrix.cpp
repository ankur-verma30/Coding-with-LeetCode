class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int low = 0, high = row - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (matrix[mid][0] > target)
                high = mid - 1;
            else if (target >= matrix[mid][0] &&
                     target <= matrix[mid][col - 1]) {
                if (binary_search(matrix[mid].begin(), matrix[mid].end(),
                                  target))
                    return true;
                    else return false;
            } else
                low = mid + 1;
        }

        return false;
    }
};