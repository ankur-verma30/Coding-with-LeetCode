class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxleftSum = values[0], n = values.size(), maxScore = 0;

        for (int i = 1; i < n; i++) {
            int currentRightScore = values[i] - i;
            maxScore = max(maxScore, maxleftSum + currentRightScore);

            int currentLeftSum = values[i] + i;
            maxleftSum = max(maxleftSum, currentLeftSum);
        }

        return maxScore;
    }
};