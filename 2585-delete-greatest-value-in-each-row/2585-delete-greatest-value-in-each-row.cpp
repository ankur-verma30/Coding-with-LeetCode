class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<priority_queue<int>> pq(row);


        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                pq[i].push(grid[i][j]);
            }
        }

        int total = 0;

        for (int i = 0; i < col; i++) {
            int maxi = 0;
            for (int j = 0; j < row; j++) {
                int element = pq[j].top();
                pq[j].pop();
                maxi = max(element, maxi);
            }
            total += maxi;
        }

        return total;
    }
};