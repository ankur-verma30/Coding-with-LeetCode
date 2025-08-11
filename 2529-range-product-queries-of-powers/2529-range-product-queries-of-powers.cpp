class Solution {
public:
    vector<int> powerList(int n) {
        int i = 30;
        vector<int> ans;
        while (n > 0 && i >= 0) {
            int val = (1 << i);
            if (val <= n) {
                ans.push_back(val);
                n -= val;
            }
            i--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers = powerList(n);

        int size = powers.size();
        vector<int> result;

        int mod = 1e9 + 7;

        for (const auto query : queries) {
            int start = query[0];
            int end = query[1];

            long long pro = 1;

            for (int i = start; i <= end; i++) {
                pro = (pro * powers[i]) % mod;
            }

            result.push_back((int)pro);
        }
        return result;
    }
};