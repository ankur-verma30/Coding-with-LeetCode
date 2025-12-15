class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int left = 0, n = prices.size(), prev = prices[0];
        long long smoothDescentPeriods = 1, count = 1;

        for (int right = 1; right < n; right++) {
            if (prices[right] + 1 == prev) {
                count++;
            } else
                count = 1;
            prev = prices[right];
            smoothDescentPeriods += count;
        }

        return smoothDescentPeriods;
    }
};