class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1)
            return -1;

        if(n==1 && m==1 && grid[n-1][m-1]==0)  return 1;

        vector<vector<int>> distance(n, vector<int>(m, INT_MAX));

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        vector<pair<int, int>> del{{-1, -1}, {-1, 0}, {-1, 1}, {0, 1},
                                   {1, 1},   {1, 0},  {1, -1}, {0, -1}};

        pq.push({1, {0, 0}});
        distance[0][0] = 1;

        while (!pq.empty()) {
            auto temp = pq.top();
            int dist = temp.first;
            int row = temp.second.first;
            int col = temp.second.second;
            pq.pop();

            for (const auto& d : del) {
                int delRow = row + d.first;
                int delCol = col + d.second;

                if (delRow >= 0 && delRow < n && delCol >= 0 && delCol < m &&
                    grid[delRow][delCol] == 0 &&
                    dist + 1 < distance[delRow][delCol]) {
                    if (delRow == n - 1 && delCol == m - 1)
                        return dist + 1;

                    distance[delRow][delCol] = dist + 1;
                    pq.push({dist + 1, {delRow, delCol}});
                }
            }
        }

        return -1;
    }
};