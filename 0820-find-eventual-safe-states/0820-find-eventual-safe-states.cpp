class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        for (int i = 0; i < n; i++) {
            for (auto it : graph[i]) {
                adj[it].push_back(i);
                 indegree[i]++;
            }
        }
        queue<int> q;
        vector<int> topo;
        int len = indegree.size();
        for (int i = 0; i < len; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int ele = q.front();
            q.pop();

            topo.push_back(ele);
            for (const auto it : adj[ele]) {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }

        sort(topo.begin(), topo.end());

        return topo;
    }
};