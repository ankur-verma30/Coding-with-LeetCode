class Solution {
public:
    void dfs(int node, vector<int>& visited, vector<int> adjList[]) {
        visited[node] = 1;
        for (auto it : adjList[node]) {
            if (visited[it] != 1)
                dfs(it, visited, adjList);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adjList[n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        vector<int> visited(n, 0);
        int count = 0;
        for (int i = 0; i < visited.size(); i++) {
            if (visited[i] == 0) {
                dfs(i, visited, adjList);
                count++;
            }
        }

        return count;
    }
};