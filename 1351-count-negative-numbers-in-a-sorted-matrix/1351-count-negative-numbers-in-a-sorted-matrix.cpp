class Solution {
public:
    int firstNegative(vector<int>& arr, int col) {
        int low = 0, high = col - 1, ans = col; // default means no negatives
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (arr[mid] < 0) {
                ans = mid;   
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return col - ans; 
    }
    
    int countNegatives(vector<vector<int>>& grid) {
        int row = grid.size(), count = 0, col = grid[0].size();
        
        for (int i = 0; i < row; i++) {
            count += firstNegative(grid[i], col);
        }
        return count;
    }
};
