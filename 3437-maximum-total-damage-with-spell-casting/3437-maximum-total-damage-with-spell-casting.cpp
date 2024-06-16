class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<int, long long> freq;
        long long TotalDamage = 0;

        for (auto& x : power) {
            freq[x]++;
        }

        unordered_map<long long, long long> dp;
        long long prevEl, backEl = 0;
        for (auto [ele, fr] : freq) {
            auto backIt = freq.lower_bound(ele - 2);
            if (backIt != freq.begin()) {
                backEl = (*(--backIt)).first;
            }
            dp[ele] = max(dp[prevEl], ele * fr + dp[backEl]);
            TotalDamage = max(TotalDamage, dp[ele]);
            prevEl = ele;
        }
        return TotalDamage;
    }
};