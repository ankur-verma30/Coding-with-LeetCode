class Solution {
public:
    long long maxEnergyBoost(vector<int>& eA, vector<int>& eB) {
        int n = eA.size();
        vector<long long> energyDpA(n, 0), energyDpB(n, 0);

        energyDpA[0] = eA[0];
        energyDpB[0] = eB[0];

        for (int i = 1; i < n; ++i) {
            energyDpA[i] = energyDpA[i - 1] + eA[i];
            energyDpB[i] = energyDpB[i - 1] + eB[i];

            if (i >= 2) {
                energyDpA[i] = max(energyDpA[i], energyDpB[i - 2] + eA[i]);
                energyDpB[i] = max(energyDpB[i], energyDpA[i - 2] + eB[i]);
            }
        }

        return max(energyDpA[n - 1], energyDpB[n - 1]);
    }
};