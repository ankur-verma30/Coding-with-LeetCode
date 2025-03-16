class Solution {
public:
    int maxSum(vector<int>& nums) {
        bool nonNegative = false;
        unordered_set<int> positive;
        int sum = 0;

        int maxNeg = -101;

        for (int x : nums) {
            if (x >= 0) {
                nonNegative = true;
                if (x > 0)
                    positive.insert(x);
            } else
                maxNeg = max(maxNeg, x);
        }

        if (nonNegative) {
            for (const auto& it : positive)
                sum += it;
            return sum;
        } else
            return maxNeg;
    }
};