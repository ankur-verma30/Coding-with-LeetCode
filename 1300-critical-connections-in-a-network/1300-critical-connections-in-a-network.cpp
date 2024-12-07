class Solution {
public:
    int timer = 1;
    void dfs(int node, int parent, vector<int>& visited,
             vector<vector<int>>& adj, vector<int>& timeofInsertion,
             vector<int>& lowestTimeofInsertion, vector<vector<int>>& bridges) {
        visited[node] = 1;

        lowestTimeofInsertion[node] = timer;
        timeofInsertion[node] = timer;
        timer++;

        for (const auto& it : adj[node]) {
            if (it == parent)
                continue;
            if (!visited[it]) {
                dfs(it, node, visited, adj, timeofInsertion,
                    lowestTimeofInsertion, bridges);

                lowestTimeofInsertion[node] =
                    min(lowestTimeofInsertion[node], lowestTimeofInsertion[it]);
                if (lowestTimeofInsertion[it] > timeofInsertion[node])
                    bridges.push_back({node, it});

            } else {
                lowestTimeofInsertion[node] =
                    min(lowestTimeofInsertion[node], lowestTimeofInsertion[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);

        for (const auto& it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int>visited(n,0);
        vector<int> timeofInsertion(n), lowestTimeofInsertion(n);
         vector<vector<int>>bridges;

        dfs(0, -1, visited, adj, timeofInsertion, lowestTimeofInsertion, bridges);

        return bridges;
    }
};