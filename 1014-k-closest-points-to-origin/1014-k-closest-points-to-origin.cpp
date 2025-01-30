class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pair<double, pair<int, int>>> pq;

        for (int i = 0; i < n; i++) {
            int xcord = points[i][0];
            int ycord = points[i][1];

            double distance = sqrt(xcord * xcord + ycord * ycord);

            pq.push({distance, {xcord, ycord}});
            if (pq.size() > k)
                pq.pop();
        }

        vector<vector<int>> ans;

        while (!pq.empty()) {
            auto it = pq.top();
            vector<int> temp = {it.second.first, it.second.second};
            ans.push_back(temp);
            pq.pop();
        }

        return ans;
    }
};