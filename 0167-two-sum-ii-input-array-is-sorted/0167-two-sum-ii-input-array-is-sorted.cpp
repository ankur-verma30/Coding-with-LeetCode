class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int val1 = nums[i];
            int complement = target - val1;

            int low = 0, high = n - 1;
            while (low <= high) {
            int mid = low + (high - low) / 2;
                if (complement == nums[mid] && mid != i)
                    return {i + 1, mid + 1};
                else if (complement < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
        }

        return {};
    }
};