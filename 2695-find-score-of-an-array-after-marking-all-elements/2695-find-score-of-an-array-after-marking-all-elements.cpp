class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        vector<int> visited(n, 0);

        for (int i = 0; i < n; i++)
            pq.push({nums[i], i});

        long long ans = 0;

        while (!pq.empty()) {
            auto it = pq.top();
            int element = it.first;
            int index = it.second;
            pq.pop();

            if (visited[index] == 1)
                continue;
            visited[index] = 1;

            ans += element;

            if (index - 1 >= 0)
                visited[index - 1] = 1;
            if (index + 1 < n)
                visited[index + 1] = 1;
        }

        return ans;
    }
};