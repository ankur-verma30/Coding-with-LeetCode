class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights,
                                        vector<vector<int>>& queries) {
        int n = heights.size(), m = queries.size();
        vector<int> ans(m, -1);
        unordered_map<int, vector<pair<int, int>>> mp;

        for (int id = 0; id < m; id++) {
            auto query = queries[id];
            int i = query[0], j = query[1];
            if (i < j && heights[i] < heights[j])
                ans[id] = j;
            else if (i > j && heights[i] > heights[j])
                ans[id] = i;
            else if (i == j)
                ans[id] = i;
            else
                mp[max(i, j)].push_back({max(heights[i], heights[j]), id});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        for (int id = 0; id < n; id++) {
            int curr = heights[id];
            while (!pq.empty() && pq.top().first < curr) {
                ans[pq.top().second] = id;
                pq.pop();
            }

            for (auto p : mp[id])
                pq.push(p);
        }

        return ans;
    }
};