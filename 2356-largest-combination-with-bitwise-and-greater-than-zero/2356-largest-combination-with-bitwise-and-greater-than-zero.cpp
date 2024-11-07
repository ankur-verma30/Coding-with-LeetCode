class Solution {
public:
    int largestCombination(vector<int>& candi) {
         int maxLen = 0;

        for (int bit = 0; bit < 25; ++bit) {
            int count = 0;
            for (int num : candi) {
                if (num & (1 << bit)) {
                    count++;
                }
            }
            maxLen = max(maxLen, count);
        }

        return maxLen;
    }
};