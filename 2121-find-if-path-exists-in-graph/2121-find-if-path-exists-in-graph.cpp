class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        if (source == destination)
            return true;

        // create an adjancey list
        vector<vector<int>> graph(n);

        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        queue<int> q;
        vector<int> visited(n, 0);
        q.push(source);
        visited[source] = 1;

        //BFS Traversal
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbour : graph[node]) {
                if (neighbour == destination)
                    return true;
                if (visited[neighbour] != 1) {
                    visited[neighbour] = 1;
                    q.push(neighbour);
                }
            }
        }
        return false;
    }
};