class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        vector<int> res(nums.begin(), nums.end());

        while (k--) {
            int value = INT_MAX, index = -1;
            for (int i = 0; i < res.size(); i++) {
                if (value > res[i]) {
                    value = res[i];
                    index = i;
                }
            }
            res[index] = value * multiplier;
        }

        return res;
    }
};