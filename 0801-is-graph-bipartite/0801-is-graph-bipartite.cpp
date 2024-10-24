class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        queue<int> q;
        int v = graph.size();
        vector<int> colors(v, -1);

        for (int i = 0; i < v;i++) {
            if (colors[i] == -1) {
                colors[i] = 0;
                q.push(i);

                while (!q.empty()) {
                    int temp = q.front();
                    q.pop();

                    for (auto curr : graph[temp]) {
                        if (colors[curr] == -1) {
                            q.push(curr);
                            colors[curr] = !colors[temp];
                        } else if (colors[curr] == colors[temp])
                            return false;
                    }
                }
            }
        }

        return true;
    }
};