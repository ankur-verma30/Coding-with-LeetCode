class Solution {
public:
    int findMinimumTime(vector<int>& strength, int K) {
        int n = strength.size();

        vector<int> order(n);
        for (int i = 0; i < n; i++)
            order[i] = i;

        int minTime = INT_MAX;

        do {
            int time = 0, X = 1;
            for (int i = 0; i < n; i++) {
                int lockStrength = strength[order[i]];

                int requiredTime = (lockStrength + X - 1) / X;
                time += requiredTime;
                X += K;
            }
            minTime = min(time, minTime);
        } while (next_permutation(order.begin(), order.end()));

        return minTime;
    }
};