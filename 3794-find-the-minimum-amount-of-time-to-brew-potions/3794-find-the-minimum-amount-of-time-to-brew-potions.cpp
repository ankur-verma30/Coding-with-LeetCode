class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();

        vector<long long> done(n, 0);

        for (int j = 0; j < m; j++) {
            long long lastTime = 0;
            for (int i = 0; i < n; i++) {
                long long startTime = max(lastTime, done[i]);
                lastTime = done[i] = startTime + (skill[i] * mana[j]);
            }

            for (int i = n - 1; i >= 1; i--) {
                done[i - 1] = done[i] - skill[i] * mana[j];
            }
        }
        return done[n - 1];
    }
};