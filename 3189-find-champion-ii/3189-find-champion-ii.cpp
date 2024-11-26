class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> inDegree(n, 0);

        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            inDegree[v]++;
        }

        int champion = 0, ans = -1;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                champion++;
                ans = i;
            }
        }

        return champion > 1 ? -1 : ans;
    }
};