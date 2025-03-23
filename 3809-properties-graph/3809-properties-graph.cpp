class Solution {
public:
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size();
        vector<unordered_set<int>> sets;
        
        for (const auto& row : properties) {
            unordered_set<int> s(row.begin(), row.end());
            sets.push_back(s);
        }

        vector<vector<int>> graph(n);
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (intersect(sets[i], sets[j]) >= k) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        vector<bool> visited(n, false);
        int components = 0;
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, graph, visited);
                components++;
            }
        }
        
        return components;
    }

private:
    void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
        visited[node] = true;
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, graph, visited);
            }
        }
    }

    int intersect(const unordered_set<int>& a, const unordered_set<int>& b) {
        int count = 0;
        for (int num : a) {
            if (b.count(num)) count++;
        }
        return count;
    }
};