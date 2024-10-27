class Solution {
public:
    int findPermutationDifference(string s, string t) {
        unordered_map<char, int> mpp;
        for (int i = 0; i < t.length(); i++)
            mpp[t[i]] = i;

        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            int index = mpp[s[i]];
            count += abs(i - index);
        }

        return count;
    }
};