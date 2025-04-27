class Solution {
public:
    static const int MOD = 1'000'000'007;

    void dfs(int curr, vector<int>& res, unordered_map<int, list<pair<int, int>>>& mpp) {
        if (mpp.find(curr) == mpp.end()) return;

        for (const auto& nbhr : mpp[curr]) {
            int nxt = nbhr.first;
            int fact = nbhr.second;
            res[nxt] = (1LL * res[curr] * fact) % MOD;
            dfs(nxt, res, mpp);
        }
    }

    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        int n = conversions.size() + 1;
        unordered_map<int, list<pair<int, int>>> mpp;

        for (const auto& arr : conversions) {
            int src = arr[0];
            int target = arr[1];
            int fact = arr[2];
            mpp[src].emplace_back(target, fact);
        }

        vector<int> res(n, -1);
        res[0] = 1;
        dfs(0, res, mpp);
        return res;
    }
};