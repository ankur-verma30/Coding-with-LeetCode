class Solution {
    struct Compare {
        bool operator()(pair<int,int>& a, pair<int,int>& b) {
            return a.first < b.first; 
        }
    };
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<int,int> pathCount;

        for (const auto &road : roads) {
            int u = road[0], v = road[1];
            pathCount[u]++;
            pathCount[v]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;
        for (const auto &[node, degree] : pathCount) {
            pq.push({degree, node});
        }

        unordered_map<int,int> routeId;
        while (!pq.empty()) {
            auto [deg, node] = pq.top();
            pq.pop();
            routeId[node] = n--;
        }

      
        long long total = 0;
        for (const auto &road : roads) {
            total += routeId[road[0]] + routeId[road[1]];
        }

        return total;
    }
};
