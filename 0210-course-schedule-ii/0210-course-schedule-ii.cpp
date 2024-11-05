class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
   vector<int> indegree(numCourses, 0);
    vector<vector<int>> graph(numCourses);

    for (const auto& pair : pre) {
        int course = pair[0];
        int prerequisite = pair[1];
        graph[prerequisite].push_back(course);
        indegree[course]++;
    }

    queue<int> q;

    for (int i = 0; i < indegree.size(); i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

   vector<int>topo;
    while (!q.empty()) {
        int ele = q.front();
        q.pop();
        topo.push_back(ele);

        for (int neighbor : graph[ele]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    int n=topo.size();
    if(n<numCourses) return {};
    else return topo;
    }
};