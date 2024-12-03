class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distance) {
        vector<vector<int>> mat(n, vector<int>(n, 1e9));

        for (const auto& edge : edges) {
            int from = edge[0];
            int to = edge[1];
            int weight = edge[2];
            mat[from][to] = weight;
            mat[to][from] = weight;
        }

        for (int i = 0; i < n; i++)
            mat[i][i] = 0;

        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (mat[i][via] != 1e9 && mat[via][j] != 1e9)
                        mat[i][j] = min(mat[i][j], (mat[i][via] + mat[via][j]));
                }
            }
        }

        int ansCity = -1, count = n + 1;
        for (int i = 0; i < n; i++) {
            int tempCount = 0;
            for (int j = 0; j < n; j++) {
                if (mat[i][j] <= distance)
                    tempCount++;
            }
            if (tempCount <= count) {
                ansCity = i;
                count = tempCount;
            }
        }

        return ansCity;
    }
};