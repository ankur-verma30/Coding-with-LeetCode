class Solution {
public:
    int isPartition(vector<int>& weights, int limit) {
        int count = 1, sum = 0;
        for (const auto it : weights) {
            if (it > limit)
                return INT_MAX;
            if (sum + it > limit) {
                count++;
                sum = it;
            } else
                sum += it;
        }
        return count;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sumOfCargos = 0;

        for (const auto& it : weights)
            sumOfCargos += it;
        int low = 1, high = sumOfCargos, ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int countAns = isPartition(weights, mid);
            if (countAns <= days) {
                ans = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }

        return ans;
    }
};