class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        long long sum = 0;
        unordered_map<int, int> mpp;

        for (int num : nums) {
            sum += num;
            mpp[num]++;
        }

        int outlier = INT_MIN;

        for (int num : nums) {
            long long requiredSum = sum - num;
            if (requiredSum % 2 != 0) continue;

            long long potentialSum = requiredSum / 2;
            mpp[num] -= 1;
            int sumElement = static_cast<int>(potentialSum);
            int count = mpp.count(sumElement) ? mpp[sumElement] : 0;
            if (count > 0) outlier = max(outlier, num);
            mpp[num] += 1;
        }

        return outlier;
    }
};