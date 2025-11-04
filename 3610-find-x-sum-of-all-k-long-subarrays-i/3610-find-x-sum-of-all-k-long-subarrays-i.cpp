class Solution {
public:
    int solve(vector<int> temp, int x) {
        int sum = 0;
        unordered_map<int, int> mpp;

        for (const auto& it : temp) {
            mpp[it]++;
            sum += it;
        }

        int mapSize = mpp.size();
        if (mapSize < x)
            return sum;

        priority_queue<pair<int, int>> pq;
        for (const auto& [value, freq] : mpp) {
            pq.push({freq, value});
        }

        sum = 0;
        while (x--) {
            auto element = pq.top();
            int value = element.second;
            int freq = element.first;
            sum += (value * freq);
            pq.pop();
        }

        return sum;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i <= n - k; i++) {
            vector<int> temp(nums.begin() + i, nums.begin() + i + k);
            int res = solve(temp, x);
            ans.push_back(res);
        }

        return ans;
    }
};