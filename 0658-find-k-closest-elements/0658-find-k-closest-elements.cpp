class Solution {
public:
    static bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second < b.second;
    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)>
            pq(cmp);
        int n = arr.size();
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            int diff = abs(x - arr[i]);
            pq.push({arr[i], diff});
            if (pq.size() > k)
                pq.pop();
        }

        while (!pq.empty()) {
            auto it = pq.top();
            ans.push_back(it.first);
            pq.pop();
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};