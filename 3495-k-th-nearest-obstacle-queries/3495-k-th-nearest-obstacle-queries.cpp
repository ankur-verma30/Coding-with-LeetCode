class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        priority_queue<int> pq;

        vector<int> ans;
        for (const auto query : queries) {
            int first = query[0];
            int second = query[1];
            int distance = abs(first) + abs(second);
            pq.push(distance);

            if (pq.size() < k)
                ans.push_back(-1);
            if (pq.size() > k)
                pq.pop();
            if (pq.size() == k)
                ans.push_back(pq.top());
        }

        return ans;
    }
};