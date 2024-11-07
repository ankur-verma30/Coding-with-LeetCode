class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
          int n = heights.size();
        int m = heights[0].size();
    
        vector<vector<int>> weights(n, vector<int>(m, INT_MAX));

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        vector<pair<int, int>> del{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        pq.push({0, {0, 0}});
        weights[0][0] = 0;

        while (!pq.empty()) {
            auto temp = pq.top();
            int weight = temp.first;
            int row = temp.second.first;
            int col = temp.second.second;
            pq.pop();

            if (row == n - 1 && col == m - 1) return weight;
            
            for (const auto& d : del) {
                int delRow = row + d.first;
                int delCol = col + d.second;

                if (delRow >= 0 && delRow < n && delCol >= 0 && delCol < m) {
                    int newWeight = max(weight, abs(heights[delRow][delCol] - heights[row][col]));
                    if (newWeight < weights[delRow][delCol]) {
                        weights[delRow][delCol] = newWeight;
                        pq.push({newWeight, {delRow, delCol}});
                    }
                }
            }
        }

        return weights[n - 1][m - 1];
    }
};