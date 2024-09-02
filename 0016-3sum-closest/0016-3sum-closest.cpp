class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int Resdiff = INT_MAX, ans = 0;

        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j+ 1; k < n; k++) {
                    int sum = nums[i] + nums[j] + nums[k];
                    int diff = abs(sum - target);
                    if (diff < Resdiff) {
                        Resdiff = diff;
                        ans = sum;
                    }
                }
            }
        }

        return ans;
    }
};