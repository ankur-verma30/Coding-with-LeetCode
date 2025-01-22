class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int row = isWater.size();
        int col = isWater[0].size();

        queue<pair<int, pair<int, int>>> q;

        vector < vector<int>> ans(row, vector<int>(col, -1));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (isWater[i][j] == 1) {
                    q.push({0, {i, j}});
                    ans[i][j] = 0;
                }
            }
        }

        vector<int> directions{-1, 0, 1, 0, -1};
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                auto temp = q.front();
                q.pop();
                int height = temp.first;
                int r = temp.second.first;
                int c = temp.second.second;
            
                for (int j = 0; j <4; j++) {
                    int nRow = r + directions[j];
                    int nCol = c + directions[j + 1];
                    if (nRow>=0 && nCol>=0 &&nRow < row && nCol < col 
                    && ans[nRow][nCol] == -1) {
                        
                        ans[nRow][nCol] = height + 1;
                        q.push({height + 1, {nRow, nCol}});
                    }
                }
            }
        }

        return ans;
    }
};