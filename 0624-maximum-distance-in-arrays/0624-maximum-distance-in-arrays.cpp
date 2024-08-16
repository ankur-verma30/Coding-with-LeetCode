class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int small = arrays[0][0], big = arrays[0].back();
        int maxDiff = 0;

        for (int i = 1; i < arrays.size(); i++) {
            maxDiff = max(maxDiff, abs(big - arrays[i][0]));
            maxDiff = max(maxDiff, abs(arrays[i].back() - small));
            small = min(small, arrays[i][0]);
            big = max(big, arrays[i].back());
        }

        return maxDiff;
    }
};