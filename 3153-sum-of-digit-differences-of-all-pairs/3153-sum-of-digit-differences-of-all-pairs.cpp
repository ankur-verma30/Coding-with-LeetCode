class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        map<pair<int, int>, long long> mpp;
        int digits = 0;

        for (auto& x : nums) {
            int index = 0;
            while (x) {
                mpp[{x % 10, index}]++;
                index++;
                x = x / 10;
            }
            digits = index;
        }

        long long answer = 1ll * (nums.size()) * (nums.size() - 1) / 2 * digits;

        for (auto& [i, j] : mpp) {
            answer -= j * (j - 1) / 2;
        }

        return answer;
    }
};