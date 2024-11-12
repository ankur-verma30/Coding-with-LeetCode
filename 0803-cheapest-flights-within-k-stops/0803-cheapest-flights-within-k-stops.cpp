class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<vector<pair<int, int>>> graph(n);

        for (const auto& it : flights) {
            graph[it[0]].push_back({it[1], it[2]});
        }

        vector<int> distance(n, INT_MAX);
        distance[src] = 0;
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});

        while (!q.empty()) {
            auto temp = q.front();
            q.pop();
            int stops = temp.first;
            int node = temp.second.first;
            int dist = temp.second.second;

            if (stops > k)
                continue;

            for (auto adjNode : graph[node]) {
                int adjacentNode = adjNode.first;
                int cost = adjNode.second;

                if (cost + dist < distance[adjacentNode] && stops <= k) {
                    distance[adjacentNode] = cost + dist;
                    q.push({stops + 1, {adjacentNode, cost + dist}});
                }
            }
        }
        return distance[dst] == INT_MAX ? -1 : distance[dst];
    }
};