class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
         unordered_map<int, int> Count;
    long long pair = 0;

    for (int x : hours) {
        int rem = x % 24;
        int hours_left = (rem == 0) ? 0 : 24 - rem;

        if (Count.find(hours_left) != Count.end()) {
            pair += Count[hours_left];
        }

        Count[rem]++;
    }

    return pair;
    }
};