class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if (n == k)
            return 0;
        vector<long long> adjacentSum;

        for (int i = 0; i < n - 1; i++) {
            long long adjacentTotal =(weights[i] + weights[i + 1]);
            adjacentSum.push_back(adjacentTotal);
        }

        sort(adjacentSum.begin(), adjacentSum.end());

        long long ans = 0;
        for (int i = 0; i < k - 1; i++) {
            ans += adjacentSum[n - i - 2] - adjacentSum[i];
        }

        return ans;
    }
};