class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {
        long long spellSize = spells.size(), potionSize = potions.size();
        vector<int> results(spellSize, 0);

        sort(potions.begin(), potions.end());

        for (long long i = 0; i < spellSize; i++) {
            long long spell=spells[i];
            long long low = 0, high = potionSize - 1;
            int ans = -1;
            while (low <= high) {
                long long mid = low + (high - low) / 2;
                if (potions[mid] * spell * 1LL < success)
                    low = mid + 1;
                else {
                    ans = mid;
                    high = mid - 1;
                }
            }
            if(ans!=-1)
            results[i] = potionSize - ans;
        }

        return results;
    }
};