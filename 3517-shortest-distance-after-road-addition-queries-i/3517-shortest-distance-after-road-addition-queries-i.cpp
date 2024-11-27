class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n,
                                             vector<vector<int>>& queries) {
        vector<vector<int>> path(n);
        vector<int> res;

        for (int i = 0; i < n - 1; ++i)
            path[i].push_back(i + 1);

        for (auto& query : queries) {
            int u = query[0];
            int v = query[1];
            path[u].push_back(v);

            vector<int> distance(n, INT_MAX);
            queue<int> q;
            distance[0] = 0;
            q.push(0);

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int neighbor : path[node]) {
                    if (distance[neighbor] > distance[node] + 1) {
                        distance[neighbor] = distance[node] + 1;
                        q.push(neighbor);
                    }
                }
            }

            res.push_back(distance[n - 1]);
        }

        return res;
    }
};