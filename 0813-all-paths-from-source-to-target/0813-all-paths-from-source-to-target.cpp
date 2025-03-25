class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size(), src = 0, dest = n - 1;

        vector<vector<int>> ans;
        vector<int> temp;
        queue<vector<int>> q;
        temp.push_back(src);

        q.push(temp);

        while (!q.empty()) {
            auto currPath = q.front();
            q.pop();

            int lastNode = currPath.back();
            if (lastNode == dest)
                ans.push_back(currPath);
            else {
                for (const auto it : graph[lastNode]) {
                    vector<int> path = currPath;
                    path.push_back(it);
                    q.push(path);
                }
            }
        }

        return ans;
    }
};