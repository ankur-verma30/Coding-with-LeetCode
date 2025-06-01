class Solution {
public:
    int getMinimum(vector<int>& temp) {
        sort(temp.begin(), temp.end());
        int minRes = INT_MAX;

        for (int i = 1; i < temp.size(); i++) {
            if (temp[i] != temp[i - 1]) {
                minRes = min(minRes, abs(temp[i] - temp[i - 1]));
            }
        }

        return minRes == INT_MAX ? 0 : minRes;
    }

    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> ans(row - k + 1, vector<int>(col - k + 1));

        for (int i = 0; i <= row - k; i++) {
            for (int j = 0; j <= col - k; j++) {
                vector<int> vals;
                for (int nRow = 0; nRow < k; nRow++) {
                    for (int nCol = 0; nCol < k; nCol++) {
                        vals.push_back(grid[i + nRow][j + nCol]);
                    }
                }
                ans[i][j] = getMinimum(vals);
            }
        }

        return ans;
    }
};
