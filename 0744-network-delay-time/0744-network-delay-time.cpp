class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n + 1);
        
        for (const auto& it : times) {
            graph[it[0]].push_back({it[1], it[2]});
        }

        vector<int> distance(n + 1, INT_MAX);
        distance[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k}); 
        while (!pq.empty()) {
            auto temp = pq.top();
            int dist = temp.first;
            int node = temp.second;
            pq.pop();

            for (auto adj : graph[node]) {
                int adjacent = adj.first;
                int time = adj.second;

                if (dist + time < distance[adjacent]) {
                    distance[adjacent] = dist + time;
                    pq.push({distance[adjacent], adjacent});
                }
            }
        }

        int maxi = 0;
        for (int i = 1; i <= n; i++) {
            if (distance[i] == INT_MAX) {
                return -1; 
            }
            maxi = max(maxi, distance[i]);
        }

        return maxi;

    }
};