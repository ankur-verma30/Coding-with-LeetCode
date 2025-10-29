class Solution {
long long findCost(int number, const vector<int>& nums, const vector<int>& cost) {
    long long totalCost = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        totalCost += 1LL * abs(number - nums[i]) * cost[i];
    }
    return totalCost;
}

public:
    long long minCost(vector<int>& nums, vector<int>& cost) {

        long long minCost = findCost(1, nums, cost);
        long long ans = 1;

        int low = 1, high = 1e6;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long tempCost = findCost(mid, nums, cost);
            long long temp2Cost = findCost(mid + 1, nums, cost);
            ans = min(tempCost, temp2Cost);
            if (tempCost < temp2Cost)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return ans;
    }
};