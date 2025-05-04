class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<string, int> mpp;

        int count = 0;

        for (const auto domino : dominoes) {
            int first = domino[0], second = domino[1];
            if (first > second)
                swap(first, second);
            string str = to_string(first) + ' ' + to_string(second);
            count += mpp[str];
            mpp[str]++;
        }

        return count;
    }
};