class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> mpp;

        for (const auto& w : word)
            mpp[w]++;
        int MinOps = word.size();

        for (const auto& [ch1, freq1] : mpp) {
            int deleted = 0;
            for (const auto& [ch2, freq2] : mpp) {
                if (freq1 > freq2)
                    deleted += freq2;
                else if (freq2 > freq1 + k)
                    deleted += freq2 - (freq1 + k);
            }
            MinOps = min(MinOps, deleted);
        }
        return MinOps;
    }
};