class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int left = 0, whiteCount = 0, minCount = INT_MAX;

        for (int right = 0; right < n; right++) {
            if (blocks[right] == 'W') whiteCount++;
            if (right - left + 1 == k) {
                minCount = min(minCount, whiteCount);
                if (blocks[left] == 'W') whiteCount--;
                left++;
            }
        }
        return minCount;
    }
};