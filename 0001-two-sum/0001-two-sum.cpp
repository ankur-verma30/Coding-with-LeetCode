class Solution {
public:
    static bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first < b.first;
    }
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size();
        vector<pair<int, int>> sorted;

        for (int i = 0; i < n; i++) {
            sorted.push_back({nums[i], i});
        }

        sort(sorted.begin(), sorted.end(), cmp);
        int left = 0, right = n - 1;

        while (left < right) {
            int sum = sorted[left].first + sorted[right].first;

            if (sum == target)
                return {sorted[left].second, sorted[right].second};
            else if (sum > target)
                right--;
            else
                left++;
        }

        return {-1, -1};
    }
};