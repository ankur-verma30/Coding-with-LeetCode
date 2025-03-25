class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> visited(n, 0);
        visited[0] = 1;

        queue<int> q;
        q.push(0);

        while (!q.empty()) {
            int top = q.front();
            q.pop();
            for (const auto& it : rooms[top]) {
                if (!visited[it]) {
                    q.push(it);
                    visited[it] = 1;
                }
            }
        }

        for (const auto it : visited) {
            if (it == 0)
                return false;
        }

        return true;
    }
};