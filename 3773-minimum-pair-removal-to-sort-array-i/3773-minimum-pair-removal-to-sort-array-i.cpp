class Solution {
public:
    bool isNonDecreasing(const vector<int>& vec) {
        for (int i = 1; i < vec.size(); i++) {
            if (vec[i] < vec[i - 1]) return false;
        }
        return true;
    }
public:
    int minimumPairRemoval(vector<int>& nums) {
        vector<int> newNums(nums);
        int ops = 0;

        while (!isNonDecreasing(newNums)) {
            int minSum = INT_MAX;
            int idx = 0;

            for (int i = 0; i < newNums.size() - 1; i++) {
                int sum = newNums[i] + newNums[i + 1];
                if (sum < minSum) {
                    minSum = sum;
                    idx = i;
                }
            }

            int merged = newNums[idx] + newNums[idx + 1];
            newNums.erase(newNums.begin() + idx + 1);
            newNums[idx] = merged;
            ops++;
        }

        return ops;
    }
};