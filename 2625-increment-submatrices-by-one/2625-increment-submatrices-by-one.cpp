class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> ans(n, vector<int>(n, 0));

        for (const auto query : queries) {
            int startRow = query[0];
            int endRow = query[2];
            int startCol = query[1];
            int endCol = query[3];

            for (int i = startRow; i <= endRow; i++) {
                ans[i][startCol]++;
                if (endCol + 1 < n)
                    ans[i][endCol + 1]--;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j == 0) continue;
                ans[i][j] += ans[i][j - 1];
            }
        }
        return ans;
    }
};