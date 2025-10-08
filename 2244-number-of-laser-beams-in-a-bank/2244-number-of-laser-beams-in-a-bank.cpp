class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int totalCount = 0, n = bank.size();
        int countOnes = count(bank[0].begin(), bank[0].end(), '1');

        for (int i = 1; i < n; i++) {
            int val = count(bank[i].begin(), bank[i].end(), '1');
            if (val > 0) {
                totalCount += (val * countOnes);
                countOnes = val;
            }
        }
        return totalCount;
    }
};